#ifndef PASS_H
#define PASS_H

#include "../../interfaces/booster.h"
#include "../cell_item.h"

class Pass: public Booster, public Cell_item{
public:
	Pass(int pos_x, int pos_y, Game_i& game_object);

	bool interaction(Cell_element& item);
	bool interaction(Attackable_entity& item);
	bool interaction(Booster& item);

	void effect(Attackable_entity& entity);

	std::shared_ptr<Cell_element> copying();
};

#endif // PASS_H
