#ifndef CELL_ITEM_H
#define CELL_ITEM_H

#include "../interfaces/cell_element.h"
#include "signals/basic_signal_output.h"
#include "signals/signal_destroy.h"
#include "../interfaces/game_i.h"

class Cell_item: public Cell_element, public Basic_signal_output{
public:
	Cell_item(int pos_x, int pos_y, Game_i& game_object);
	void destroy();
	int get_x() const;
	int get_y() const;
	size_t unique_number() const;
	void update() {}

protected:
	int x;
	int y;
	Game_i& game;
};

#endif // CELL_ITEM_H
