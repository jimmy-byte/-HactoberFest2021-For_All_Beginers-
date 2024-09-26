class ApplicationController < ActionController::Base
    include SessionHelper

    def require_user
        if !logged_in?
            flash[:danger] = "You must be logged in to perform this action!"
            redirect_to root_url
        end
    end

    def require_same_user 
        if !logged_in? && current_user != @user
            flash[:danger] = "You can't perform this action!"
            redirect_to root_url
        end
    end
end
