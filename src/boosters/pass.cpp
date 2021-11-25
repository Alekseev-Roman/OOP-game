#include "../../inc/headers/boosters/pass.h"

Pass::Pass(int pos_x, int pos_y, Game_i& game_object):
	Cell_item::Cell_item(pos_x, pos_y, game_object){}

bool Pass::interaction(Cell_element& item){
	return item.interaction((Booster&)*this);
}

bool Pass::interaction(Attackable_entity& item){
	if(item.check_take_item()){
		effect(item);
		return true;
	}
	return false;
}

bool Pass::interaction(Booster& item){
	return false;
}

void Pass::effect(Attackable_entity& entity){
	if(entity.check_take_item()){
		game.add_pass();
		destroy();
	}
}

std::shared_ptr<Cell_element> Pass::copying(){
	return std::make_shared<Pass>(get_x(), get_y(), game);
}
