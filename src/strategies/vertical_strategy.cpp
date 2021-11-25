#include "../../inc/headers/strategies/vertical_strategy.h"

void Vertical_strategy::strategy_enemy(Enemy& enemy){
	bool ok_move;
	int new_y = enemy.get_y();
	if(flag_direction){
		new_y++;
	} else {
		new_y--;
	}
	ok_move = enemy.move(enemy.get_x(), new_y);
	if(!ok_move){
		if(flag_direction){
			new_y -= 2;
		} else {
			new_y += 2;
		}
		flag_direction = !flag_direction;
		enemy.move(enemy.get_x(), new_y);
	}
}

