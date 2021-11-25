#include "../inc/headers/cell.h"

Cell::Cell(bool is_wall):
	wall(is_wall){}

std::unique_ptr<Cell> Cell::copying_cell(){
	return std::make_unique<Cell>(wall);
}

std::shared_ptr<Cell_element> Cell::get_element() const{
	return element;
}

bool Cell::check_element() const{
	return element != nullptr;
}

void Cell::set_element(const std::shared_ptr<Cell_element>& ptr_cell_element){
	element = ptr_cell_element;
}

bool Cell::check_wall() const{
	return wall;
}
