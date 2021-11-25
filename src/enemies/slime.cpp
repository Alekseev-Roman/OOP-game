#include "../../inc/headers/enemies/slime.h"

Slime::Slime(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object):
	Enemy::Enemy(pos_x, pos_y, default_health, default_armor, default_damage, game_object){}

std::shared_ptr<Cell_element> Slime::copying(){
	return std::make_shared<Slime>(get_x(), get_y(), get_health(), get_armor(), get_damage(), game);
}

bool Slime::check_take_item() const{
	return false;
}

bool Slime::check_attack() const{
	return false;
}

