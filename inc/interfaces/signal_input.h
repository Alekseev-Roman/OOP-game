#ifndef SIGNAL_INPUT_H
#define SIGNAL_INPUT_H

#include "cell_element.h"
#include "signal.h"

class Signal;

class Signal_input{
public:
	virtual ~Signal_input() = default;
	virtual void signal_accept(const Signal& signal) = 0;
	virtual void signal_move(Cell_element& element, int new_x, int new_y) = 0;
	virtual void signal_fight(Cell_element& element, int coeff_damage) = 0;
	virtual void signal_take(Cell_element& element) = 0;
	virtual void signal_destroy(Cell_element& element) = 0;
};

#endif // SIGNAL_INPUT_H
