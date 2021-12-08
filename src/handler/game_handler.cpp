#include "../../inc/headers/handler/game_handler.h"
#include <iostream>

Game_handler::Game_handler(Game_i& g):
	game{g} {}

void Game_handler::handle(Command command){
	next_handler->handle(command);
}
