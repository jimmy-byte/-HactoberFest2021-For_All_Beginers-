class AssignController < ApplicationController 
    before_action :require_user
    def edit 
        @bug = Bug.find(params[:id])
        @all_users = User.all
        @users = []
        @all_users.each do |user|
            if user.role == 1 or user.role == 2
                @users << user.name
            end
        end
    end

    def assign
    end
    def update
        @bug = Bug.find(params[:id])
        
        if @bug.update_column(:assigned_to, params[:bug][:assigned_to])
            flash[:success] = "Bug Assigned successfully!"
            redirect_to bugs_path
        else
            render 'assign_bug'
        end
    end

end