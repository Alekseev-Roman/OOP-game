#ifndef MOVABLE_ELEMENT_H
#define MOVABLE_ELEMENT_H

#include "../interfaces/movable.h"
#include "signals/signal_move.h"
#include "cell_item.h"

class Movable_element: public Movable, public Cell_item{
public:
	using Cell_item::Cell_item;
	
	bool move(int pos_x, int pos_y);
};

#endif // MOVABLE_ELEMENT_H
