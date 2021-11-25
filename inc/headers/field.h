#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include "cell.h"

class Cell;

class Field{
public:
	Field(int height_field, int width_field);
	Field(const Field& field);
	Field(Field&& field);
	Cell& get_cell(int x, int y) const;
	Field& operator = (const Field& field);
	Field& operator = (Field&& field);
	int get_height() const;
	int get_width() const;
	void set_cell(std::unique_ptr<Cell>&& cell, int x, int y);

private:
	using cell_ptr = std::unique_ptr<Cell>;
	using cell_ptr_ptr = std::unique_ptr<cell_ptr[]>;
	std::unique_ptr<cell_ptr_ptr[]> arr_cells;
	int height;
	int width;
	std::unique_ptr<Cell> wall = std::make_unique<Cell>(true);
};

#endif // FIELD_H
