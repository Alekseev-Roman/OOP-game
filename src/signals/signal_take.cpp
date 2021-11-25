#include "../../inc/headers/signals/signal_take.h"

Signal_take::Signal_take(Cell_element& element):
	cell_el(element) {}

void Signal_take::signal_processing(Signal_input& signal) const{
	signal.signal_take(cell_el);
}
