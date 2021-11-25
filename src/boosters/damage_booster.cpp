#include "../../inc/headers/boosters/damage_booster.h"

void Damage_booster::effect(Attackable_entity& entity){
	if(entity.check_take_item()){
		entity.change_damage(diff_characteristic);
		destroy();
	}
}

std::shared_ptr<Cell_element> Damage_booster::copying(){
	return std::make_shared<Damage_booster>(get_x(), get_y(), get_diff_characteristic(), game);
}
