#include "../../inc/headers/enemies/player.h"
#include "../../inc/headers/handler/player_handler.h"
#include <iostream>

Player::Player(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object):
	Entity::Entity(pos_x, pos_y, default_health, default_armor, default_damage, game_object){
		attack_flag = true;
		command_handler = std::make_shared<Player_handler>(*this);
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
	move(get_x() + diff_pos_x, get_y() + diff_pos_y);
	diff_pos_y = 0;
	diff_pos_x = 0;
}

bool Player::move(int pos_x, int pos_y){
//	std::cout << pos_x <<  " " <<  pos_y  << std::endl;
	bool flag_move = Entity::move(pos_x, pos_y);
	if(flag_move){
		game.get_cell(pos_x, pos_y).check_player();
	}
	return flag_move;
}


void Player::move_to(int diff_x, int diff_y){
	diff_pos_y = diff_y;
	diff_pos_x = diff_x;
}

std::shared_ptr<Command_handler> Player::get_command_handler() const{
	return command_handler;
}