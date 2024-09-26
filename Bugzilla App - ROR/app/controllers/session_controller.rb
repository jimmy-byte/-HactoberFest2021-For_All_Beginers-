class SessionController < ApplicationController
  def new
  end

  def create
    @user = User.find_by(email: params[:session][:email].downcase)
    if @user && @user.authenticate(params[:session][:password])
      if @user.activated?
        log_in @user
        redirect_to root_path
      else
        message = "Account not activated."
        message += "Check you email for the activation link."
        flash[:warning] = message
        redirect_to root_url
      end
    else
      flash.now[:danger] = "Invalid Email or Password combination"
      render 'new'
    end
  end

  def destroy
   log_out
   redirect_to root_path
  end

end
