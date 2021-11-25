#ifndef SIGNAL_MOVE_H
#define SIGNAL_MOVE_H

#include "../../interfaces/signal.h"

class Signal_move: public Signal{
public:
	Signal_move(Cell_element& element, int new_x, int new_y);
	void signal_processing(Signal_input& signal) const;

private:
	Cell_element& cell_el;
	int x;
	int y;
};

#endif // SIGNAL_MOVE_H
