#include "../inc/headers/field.h"

Field::Field(int height_field, int width_field):
	height(height_field), width(width_field){
		arr_cells = std::make_unique<cell_ptr_ptr[]>(height);
		for(int i = 0; i < height; i++){
			arr_cells[i] = std::make_unique<cell_ptr[]>(width);
		}
	}

Field::Field(const Field& field):
	Field(field.height, field.width){
		for(int i = 0; i < height; i++){
			for(int e = 0; e < width; e++){
				arr_cells[i][e] = field.arr_cells[i][e]->copying_cell();
			}
		}
	}

Field::Field(Field&& field):
	height(field.height), width(field.width){
		arr_cells = nullptr;
		std::swap(arr_cells, field.arr_cells);
	}

Cell& Field::get_cell(int x, int y) const{
	if(x < 0 || x > 14 || y < 0 || y > 9)
		return *wall;
	return *arr_cells[y][x];
}

Field& Field::operator = (const Field& field){
	if(&field == this)
		return *this;
	height = field.height;
	width = field.width;
	arr_cells = std::make_unique<cell_ptr_ptr[]>(height);
	for(int i = 0; i < height; i++){
		arr_cells[i] = std::make_unique<cell_ptr[]>(width);
		for(int e = 0; e < width; e++){
			arr_cells[i][e] = field.arr_cells[i][e]->copying_cell();
		}
	}
	return *this;
}

Field& Field::operator = (Field&& field){
	if(&field == this)
		return *this;
	height = field.height;
	width = field.width;
	arr_cells = nullptr;
	std::swap(arr_cells, field.arr_cells);
	return *this;
}

int Field::get_height() const{
	return height;
}

int Field::get_width() const{
	return width;
}

void Field::set_cell(std::unique_ptr<Cell>&& cell, int x, int y){
	arr_cells[y][x] = std::move(cell);
}
