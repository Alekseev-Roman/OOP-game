#include "../../inc/headers/enemies/infected_astronaut.h"

Infected_astronaut::Infected_astronaut(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object):
	Enemy::Enemy(pos_x, pos_y, default_health, default_armor, default_damage, game_object){}

std::shared_ptr<Cell_element> Infected_astronaut::copying(){
	return std::make_shared<Infected_astronaut>(get_x(), get_y(), get_health(), get_armor(), get_damage(), game);
}

bool Infected_astronaut::check_take_item() const{
	return false;
}

bool Infected_astronaut::check_attack() const{
	return false;
}

