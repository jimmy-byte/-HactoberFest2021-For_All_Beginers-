class AddAssignedToToBug < ActiveRecord::Migration[6.0]
  def change
    add_column :bugs, :assigned_to, :string
  end
end
