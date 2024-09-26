class User < ApplicationRecord

    has_many :bugs

    attr_accessor :activation_token

    before_save :downcase_email
    before_save :downcase_name
    before_create :create_activation_digest

    
    validates :name, presence:true, length: { maximum: 50 }, uniqueness: true
    VALID_EMAIL_REGEX = /\A[\w+\-.]+@[a-z\d\-.]+\.[a-z]+\z/i
    validates :email, presence:true, length: { maximum: 255 }, format: { with: VALID_EMAIL_REGEX }, uniqueness: true
    has_secure_password
    validates :password, presence:true, length: { minimum: 6 }, allow_nil: true
    ROLE_LIST = [0, 1, 2]

    # Returns the hash digest of the given string.
    def User.digest(string)
        cost = ActiveModel::SecurePassword.min_cost ?
        BCrypt::Engine::MIN_COST :
        BCrypt::Engine.cost
        BCrypt::Password.create(string, cost: cost)
    end

    # returns a random token
    def User.new_token
        SecureRandom.urlsafe_base64
    end


    def authenticated?(attribute, token)
        digest = send("#{attribute}_digest")
        return false if digest.nil?
        BCrypt::Password.new(digest).is_password?(token)
    end

    
    private
        def downcase_email
            self.email = email.downcase
        end
        def downcase_name
            self.name = name.downcase
        end
        def create_activation_digest
            self.activation_token = User.new_token
            self.activation_digest = User.digest(activation_token)
        end
end
