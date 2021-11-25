#include "../../inc/headers/enemies/player.h"
#include <iostream>

Player::Player(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object):
	Entity::Entity(pos_x, pos_y, default_health, default_armor, default_damage, game_object){
		attack_flag = true;
	}


bool Player::check_take_item() const{
	return true;
}

std::shared_ptr<Cell_element> Player::copying(){
	return std::make_shared<Player>(get_x(), get_y(), get_health(), get_armor(), get_damage(), game);
}

bool Player::check_attack() const{
	return true;
}

void Player::update(){
	static bool flag_direction = false;
	bool ok_move;
	int new_y = get_y();
	if(flag_direction){
		new_y++;
	} else {
		new_y--;
	}
	ok_move = move(get_x(), new_y);
	if(!ok_move){
		if(flag_direction){
			new_y -= 2;
		} else {
			new_y += 2;
		}
		flag_direction = !flag_direction;
		move(get_x(), new_y);
	}
}

bool Player::move(int pos_x, int pos_y){
	bool flag_move = Entity::move(pos_x, pos_y);
	if(flag_move){
		game.get_cell(pos_x, pos_y).check_player();
	}
	return flag_move;
}
