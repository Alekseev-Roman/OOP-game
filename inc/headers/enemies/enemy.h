#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "../../interfaces/strategy.h"

class Strategy;

class Enemy: public Entity{
public:
	using Entity::Entity;

	bool check_take_item() const;
	void update();
	void set_strategy(std::unique_ptr<Strategy>&& new_strategy);
	void destroy();

private:
	std::unique_ptr<Strategy> strategy;
};

#endif // ENEMY_H
