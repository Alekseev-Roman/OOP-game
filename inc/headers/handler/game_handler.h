#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

#include "base_handler.h"
#include "../../interfaces/game_i.h"

class Game_handler:public Base_handler{
public:
	Game_handler(Game_i& g);
	void handle(Command command);

private:
	Game_i& game;
};

#endif // GAME_HANDLER_H
