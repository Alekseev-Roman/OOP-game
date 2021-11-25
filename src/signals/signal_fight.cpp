#include "../../inc/headers/signals/signal_fight.h"

Signal_fight::Signal_fight(Cell_element& element, int coeff_damage):
	cell_el(element), damage(coeff_damage) {}

void Signal_fight::signal_processing(Signal_input& signal) const{
	signal.signal_fight(cell_el, damage);
}
