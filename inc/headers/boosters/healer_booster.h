#ifndef HEALER_H
#define HEALER_H

#include "basic_booster.h"

class Healer_booster: public Basic_booster{
public:
	using Basic_booster::Basic_booster;
	void effect(Attackable_entity& entity);
	std::shared_ptr<Cell_element> copying();
};

#endif // HEALER_H
