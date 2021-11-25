#ifndef CELL_H
#define CELL_H

#include <memory>
#include "../interfaces/cell_element.h"

class Cell{
public:
	Cell(bool is_wall);
	virtual ~Cell() = default;
	virtual std::unique_ptr<Cell> copying_cell();
	std::shared_ptr<Cell_element> get_element() const;
	bool check_element() const;
	void set_element(const std::shared_ptr<Cell_element>& ptr_cell_element);
	bool check_wall() const;
	virtual void check_player() const {}
	
private:
	bool wall;
	std::shared_ptr<Cell_element> element;
};


#endif // CELL_H
