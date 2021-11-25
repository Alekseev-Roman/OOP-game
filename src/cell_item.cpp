#include "../inc/headers/cell_item.h"
#include "../inc/headers/game.h"

Cell_item::Cell_item(int pos_x, int pos_y, Game_i& game_object):
	x(pos_x), y(pos_y), game(game_object){}

void Cell_item::destroy(){
	game.odject_destroyed(*this);
	game.get_cell(x, y).set_element(nullptr);
	signal_send(Signal_destroy(*this));
}

int Cell_item::get_x() const{
	return x;
}

int Cell_item::get_y() const{
	return y;
}

size_t Cell_item::unique_number() const{
	return reinterpret_cast<size_t>(this);
}
