#ifndef DAMAGE_BOOSTER_H
#define DAMAGE_BOOSTER_H

#include "basic_booster.h"

class Damage_booster: public Basic_booster{
public:
	using Basic_booster::Basic_booster;
	void effect(Attackable_entity& entity);
	std::shared_ptr<Cell_element> copying();
};

#endif // DAMAGE_BOOSTER_H
