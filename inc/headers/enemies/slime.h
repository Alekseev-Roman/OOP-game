#ifndef SLIME_H
#define SLIME_H

#include "enemy.h"

class Slime: public Enemy{
public:
	Slime(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object);
	~Slime() = default;
	std::shared_ptr<Cell_element> copying();
	bool check_take_item() const;
	bool check_attack() const;
};

#endif // SLIME_H
