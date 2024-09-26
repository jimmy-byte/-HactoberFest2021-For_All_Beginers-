class CreateAssigns < ActiveRecord::Migration[6.0]
  def change
    create_table :assigns do |t|
      t.string :assigned_to
      t.references :bug, null: false, foreign_key: true

      t.timestamps
    end
  end
end
