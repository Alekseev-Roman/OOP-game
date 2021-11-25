#include "../../inc/headers/signals/signal_destroy.h"

Signal_destroy::Signal_destroy(Cell_element& element):
	cell_el(element) {}

void Signal_destroy::signal_processing(Signal_input& signal) const{
	signal.signal_destroy(cell_el);
}
