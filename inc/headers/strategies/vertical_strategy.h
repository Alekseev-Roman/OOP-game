#ifndef VERTICAL_STRATEGY_H
#define VERTICAL_STRATEGY_H

#include "../../interfaces/strategy.h"

class Vertical_strategy: public Strategy{
public:
	void strategy_enemy(Enemy& enemy);

private:
	bool flag_direction = true;
};

#endif // VERTICAL_STRATEGY_H
