#include "../../inc/headers/boosters/healer_booster.h"

void Healer_booster::effect(Attackable_entity& entity){
	if(entity.check_take_item()){
		entity.change_health(diff_characteristic);
		destroy();
	}
}

std::shared_ptr<Cell_element> Healer_booster::copying(){
	return std::make_shared<Healer_booster>(get_x(), get_y(), get_diff_characteristic(), game);
}


