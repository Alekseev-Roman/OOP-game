#include "../../inc/headers/boosters/armor_booster.h"

void Armor_booster::effect(Attackable_entity& entity){
	if(entity.check_take_item()){
		entity.change_armor(diff_characteristic);
		destroy();
	}
}

std::shared_ptr<Cell_element> Armor_booster::copying(){
	return std::make_shared<Armor_booster>(get_x(), get_y(), get_diff_characteristic(), game);
}
