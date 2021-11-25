#ifndef LOGGER_H
#define LOGGER_H

#include "../headers/signals/basic_signal_input.h"

class Logger: public Basic_signal_input{
public:
	virtual ~Logger() = default;
	virtual void signal_move(Cell_element& element, int new_x, int new_y) = 0;
	virtual void signal_fight(Cell_element& element, int coeff_damage) = 0;
	virtual void signal_take(Cell_element& element) = 0;
	virtual void signal_destroy(Cell_element& element) = 0;
};

#endif // LOGGER_H
