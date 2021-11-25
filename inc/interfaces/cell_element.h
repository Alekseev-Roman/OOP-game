#ifndef CELL_ELEMENT_H
#define CELL_ELEMENT_H

#include <memory>
#include "attackable_entity.h"
#include "booster.h"

class Cell_element{
public:
	virtual void destroy() = 0;
	virtual int get_x() const = 0;
	virtual int get_y() const = 0;
	virtual bool interaction(Cell_element& item) = 0;
	virtual bool interaction(Attackable_entity& item) = 0;
	virtual bool interaction(Booster& item) = 0;
	virtual std::shared_ptr<Cell_element> copying() = 0;
	virtual size_t unique_number() const = 0;
	virtual void update() = 0;
};

#endif // CELL_ELEMENT_H

