#include "../../inc/headers/signals/signal_move.h"

Signal_move::Signal_move(Cell_element& element, int new_x, int new_y):
	cell_el(element), x(new_x), y(new_y) {}


void Signal_move::signal_processing(Signal_input& signal) const{
	signal.signal_move(cell_el, x, y);
}
