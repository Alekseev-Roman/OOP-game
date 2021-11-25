#include "../../inc/headers/boosters/basic_booster.h"

Basic_booster::Basic_booster(int pos_x, int pos_y, int size_diff_characteristic, Game_i& game_object):
	Cell_item::Cell_item(pos_x, pos_y, game_object), diff_characteristic(size_diff_characteristic){}

bool Basic_booster::interaction(Cell_element& item){
	return item.interaction((Booster&)*this);
}

bool Basic_booster::interaction(Attackable_entity& item){
	if(item.check_take_item()){
		effect(item);
		return true;
	}
	return false;
}

bool Basic_booster::interaction(Booster& item){
	return false;
}

int Basic_booster::get_diff_characteristic(){
	return diff_characteristic;
}

