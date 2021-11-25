#include "../inc/headers/finish_cell.h"
#include <iostream>

Finish_cell::Finish_cell(Game_i& game_object):
	Cell::Cell(false), game(game_object){}

void Finish_cell::check_player() const{
	game.finish();
} 
