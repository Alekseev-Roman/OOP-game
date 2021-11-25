#ifndef PARASITE_H
#define PARASITE_H

#include "enemy.h"

class Parasite: public Enemy{
public:
	Parasite(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object);
	~Parasite() = default;
	std::shared_ptr<Cell_element> copying();
	bool check_take_item() const;
	bool check_attack() const;
};

#endif // PARASITE_H
