class AddCreatedByToBugs < ActiveRecord::Migration[6.0]
  def change
    add_column :bugs, :created_by, :integer
  end
end
