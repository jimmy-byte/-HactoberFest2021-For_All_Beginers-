class AddCommentToBug < ActiveRecord::Migration[6.0]
  def change
    add_column :bugs, :comment, :text
  end
end
