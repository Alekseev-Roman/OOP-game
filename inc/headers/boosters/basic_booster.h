#ifndef BASIC_BOOSTER_H
#define BASIC_BOOSTER_H

#include "../../interfaces/booster.h"
#include "../cell_item.h"

class Basic_booster: public Booster, public Cell_item{
public:
	Basic_booster(int pos_x, int pos_y, int size_diff_characteristic, Game_i& game_object);

	int get_diff_characteristic();

	bool interaction(Cell_element& item);
	bool interaction(Attackable_entity& item);
	bool interaction(Booster& item);

protected:
	int diff_characteristic;
};

#endif // BASIC_BOOSTER_H
