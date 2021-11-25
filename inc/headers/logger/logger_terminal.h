#ifndef LOGGER_TERMINAL_H
#define LOGGER_TERMINAL_H

#include "../../interfaces/logger.h"
#include "../signals/basic_signal_input.h"
#include "../../interfaces/cell_element.h"

#include <iostream>
#include <fstream>
#include <map>

class Logger_terminal: public Logger{
public:
	Logger_terminal();
	~Logger_terminal();
	void signal_move(Cell_element& element, int new_x, int new_y);
	void signal_fight(Cell_element& element, int coeff_damage);
	void signal_take(Cell_element& element);
	void signal_destroy(Cell_element& element);

};

#endif // LOGGER_TERMINAL_H
