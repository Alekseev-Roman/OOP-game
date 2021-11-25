#ifndef PAINTER_H
#define PAINTER_H

#include <string>
#include "../headers/field.h"

class Field;

class Painter{
public:
	virtual ~Painter() = default;
	virtual void set_field(const Field& field) = 0;
	virtual void paint_cell(const std::string& cell_texture, int x, int y) = 0;
	virtual void paint_window() = 0;
	virtual bool check_window() = 0;
	virtual void set_element(const std::string& texture, Cell_element& element) = 0;
};

#endif // PAINTER_H
