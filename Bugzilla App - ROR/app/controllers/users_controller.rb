class UsersController < ApplicationController
  before_action :require_user, except: [:new]
  before_action :require_same_user

  def new
    @user = User.new
  end

  def create
    #render plain: params[:user].inspect
    @user = User.new(user_params)
    if @user.save
      # log_in @user
      # flash[:success] = "Welcome to Bugzilla App!"
      # redirect_to root_path
      UserMailer.account_activation(@user).deliver_now
      flash[:info] = "Please check your email to activate your account."
      redirect_to root_url
    else
      render 'new'
    end
  end

  
  def change_role
    @users_all = User.all 
  end
  
  def edit 
    @user = User.find(params[:id])
    @users_all = User.all 
    @users = []
    @users_all.each do |u|
      if u.role == 1 or u.role == 2
        @users << u.name
      end
    end
  end

  def update
    @user = User.find(params[:id])
    if @user.update(change_role_param)
      flash[:success] = "Role changed successfully!"
      redirect_to change_role_path
    else
      render 'edit'
    end
  end


  private
    def user_params
      params.require(:user).permit(:name,:email,:password,:password_confirmation,:role)
    end
    def change_role_param
      params.require(:user).permit(:role)
    end
end
