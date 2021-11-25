#ifndef SIGNAL_FIGHT_H
#define SIGNAL_FIGHT_H

#include "../../interfaces/signal.h"

class Signal_fight: public Signal{
public:
	Signal_fight(Cell_element& element, int coeff_damage);
	void signal_processing(Signal_input& signal) const;

private:
	Cell_element& cell_el;
	int damage;

};

#endif // SIGNAL_FIGHT_H
