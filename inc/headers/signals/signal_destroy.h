#ifndef SIGNAL_DESTROY_H
#define SIGNAL_DESTROY_H

#include "../../interfaces/signal.h"

class Signal_destroy: public Signal{
public:
	Signal_destroy(Cell_element& element);
	void signal_processing(Signal_input& signal) const;

private:
	Cell_element& cell_el;
};

#endif // SIGNAL_DESTROY_H
