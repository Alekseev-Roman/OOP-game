#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "../../interfaces/command_handler.h"

class Player_handler;

class Player: public Entity{
public:
	Player(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object);

	bool check_take_item() const;
	bool check_attack() const;
	std::shared_ptr<Cell_element> copying();
	void update();
	bool move(int pos_x, int pos_y);
	void move_to(int diff_x, int diff_y);
	std::shared_ptr<Command_handler> get_command_handler() const;

private:
	int diff_pos_x = 0;
	int diff_pos_y = 0;
	std::shared_ptr<Command_handler> command_handler;
};

#endif // PLAYER_H
