#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player: public Entity{
public:
	Player(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object);

	bool check_take_item() const;
	bool check_attack() const;
	std::shared_ptr<Cell_element> copying();
	void update();
	bool move(int pos_x, int pos_y);
};

#endif // PLAYER_H
