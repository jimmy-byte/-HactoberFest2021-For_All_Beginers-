class Bug < ApplicationRecord
  belongs_to :user
  has_many :assigns
  before_save { self.title = title.downcase }
  default_scope -> { order(created_at: :desc) }

  validates :title, presence: true, length: { maximum: 255}, uniqueness: true
  validates :description, presence: true, length: { minimum: 10 }
  validates :created_by, presence: true
  
  
end
