#ifndef SIGNAL_TAKE_H
#define SIGNAL_TAKE_H

#include "../../interfaces/signal.h"

class Signal_take: public Signal{
public:
	Signal_take(Cell_element& element);
	void signal_processing(Signal_input& signal) const;

private:
	Cell_element& cell_el;
};

#endif // SIGNAL_TAKE_H
