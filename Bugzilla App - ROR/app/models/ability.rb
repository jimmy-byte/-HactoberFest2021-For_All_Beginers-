# frozen_string_literal: true

class Ability
  include CanCan::Ability

  def initialize(user)
    user ||= User.new # guest user (not logged in)
    if user.present?
      if user.role == 0
        can :manage, :all
      else
        if user.role == 1
          can :update, Bug
          can :create, Bug
        end
        if user.role == 2
          can :update, Bug
      end
      end
end
