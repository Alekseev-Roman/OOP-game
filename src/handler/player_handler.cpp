#include "../../inc/headers/handler/player_handler.h"
#include <iostream>

Player_handler::Player_handler(Player& p):
	player{p} {}

void Player_handler::handle(Command key){
	switch(key){
		case Command::Up:
			player.move_to(0, -1);
			break;

		case Command::Down:
			player.move_to(0, 1);
			break;

		case Command::Left:
			player.move_to(-1, 0);
			break;

		case Command::Right:
			player.move_to(1, 0);
			break;

		default:
			if(next_handler)
				next_handler->handle(key);
			break;
	}
}