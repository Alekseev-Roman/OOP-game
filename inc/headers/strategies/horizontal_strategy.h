#ifndef HORIZONTAL_STRATEGY_H
#define HORIZONTAL_STRATEGY_H

#include "../../interfaces/strategy.h"

class Horizontal_strategy: public Strategy{
public:
	void strategy_enemy(Enemy& enemy);

private:
	bool flag_direction = true;
};

#endif // HORIZONTAL_STRATEGY_H
