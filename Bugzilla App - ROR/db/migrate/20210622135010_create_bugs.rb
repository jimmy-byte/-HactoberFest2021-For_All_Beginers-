class CreateBugs < ActiveRecord::Migration[6.0]
  def change
    create_table :bugs do |t|
      t.string :title
      t.text :description
      t.string :priority
      t.integer :days_to_complete
      t.string :status
      t.references :user, null: false, foreign_key: true

      t.timestamps
    end
    add_index :bugs, [:user_id, :created_at]
  end
end
