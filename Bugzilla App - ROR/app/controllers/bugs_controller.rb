class BugsController < ApplicationController
    before_action :require_user

    def index
        @bugs = Bug.paginate(page: params[:page])
    end

    def new 
        @bug = Bug.new
        @all_users = User.all
        @users = []
        @developers = []
        @all_users.each do |user|
            if user.role == 1 or user.role == 2
                @users << user.name
            end
            if user.role == 2
                @developers << user.name
            end
        end
    end

    def create
        @bug = Bug.new(bug_params)
        @bug.user = current_user
        @bug.created_by = current_user.id
        
        @all_users = User.all
        @users = []
        @developers = []
        @all_users.each do |user|
            if user.role == 1 or user.role == 2
                @users << user.name
            end
            if user.role == 2
                @developers << user.name
            end
        end

        if @bug.save
            flash[:success] = "Bug has been created successfully!"
            redirect_to bugs_path
        else
            render 'new'
        end
    end

    def edit
        @bug = Bug.find(params[:id])
    end
    
    def update
        @bug = Bug.find(params[:id])
        if @bug.update(update_status_param)
            flash[:success] = "Bug status updated successfully!"
            redirect_to bugs_path 
        else
            render 'edit'
        end

    end

   
    def destroy
        @bug = Bug.find(params[:id])
        @bug.destroy
        flash[:success] = "Bug deleted successfully!"
        redirect_to bugs_path
    end


    # def show
    #     @all_users = User.all
    #     @users = []
    #     @all_users.each do |user|
    #         if user.role == 1 or user.role == 2
    #             @users << user.name
    #         end
    #     end
    #     if @bug.update(assign_param)
    #         flash[:success] = "Bug assigned successfully!"
    #         redirect_to bugs_path
    #     else
    #         render 'show'
    #     end
    #     #render plain: @users
    # end

    def assign_bug
        @all_users = User.all
        @users = []
        @all_users.each do |user|
            if user.role == 1 or user.role == 2
                @users << user.name
            end
        end

        @bug = Bug.find(params[:id])
        
        # params.bug = {
        #     "type": params.assigned_to,
        #     "id": params.id
        # }
        
        if @bug.update(assign_param)
            flash[:success] = "Bug assigned successfully!"
            redirect_to bugs_path
        else
            render 'assign_bug'
        end

    end

    def comment 
        @bug = Bug.find(params[:id])
    end

    def add_comment
        @bug = Bug.find(params[:id])
        
        if @bug.update_column(:comment, params[:bug][:comment])
            flash[:success] = "Comment added successfully!"
            redirect_to bugs_path
        else
            render 'comment'
        end
    end
   

    def assign
        @bug = Bug.find(params[:id])
        if @bug.update_column(:assigned_to, params[:bug][:assigned_to])
            flash[:success] = "Bug Assigned successfully!"
            redirect_to bugs_path
        else
            render 'assign_bug'
        end
    end


    private
    def bug_params
      params.require(:bug).permit(:title,:description,:priority,:days_to_complete,:status,:assigned_to)
    end

    def update_status_param
        params.require(:bug).permit(:status)
    end

    def assign_param
        params.require(:bug).permit(:assigned_to)
    end

    def comment_param
        params.require(:bug).permit(:comment)
    end

end