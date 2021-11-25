#ifndef STRATEGY_H
#define STRATEGY_H

#include "../headers/enemies/enemy.h"

class Enemy;

class Strategy{
public:
	virtual ~Strategy() = default;
	virtual void strategy_enemy(Enemy& enemy) = 0;
};

#endif // STRATEGY_H
