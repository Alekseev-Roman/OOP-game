#ifndef INFECTED_ASTRONAUT_H
#define INFECTED_ASTRONAUT_H

#include "enemy.h"

class Infected_astronaut: public Enemy{
public:
	Infected_astronaut(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object);
	~Infected_astronaut() = default;
	std::shared_ptr<Cell_element> copying();
	bool check_take_item() const;
	bool check_attack() const;
};

#endif // INFECTED_ASTRONAUT_H
