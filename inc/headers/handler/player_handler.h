#ifndef PLAYER_HANDLER_H
#define PLAYER_HANDLER_H

#include "base_handler.h"
#include "../enemies/player.h"

class Player_handler: public Base_handler{
public:
	Player_handler(Player& p);
	void handle(Command key);

private:
	Player& player;
};

#endif // PLAYER_HANDLER_H
