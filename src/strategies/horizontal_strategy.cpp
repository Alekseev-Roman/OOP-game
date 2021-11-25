#include "../../inc/headers/strategies/horizontal_strategy.h"

void Horizontal_strategy::strategy_enemy(Enemy& enemy){
	bool ok_move;
	int new_x = enemy.get_x();
	if(flag_direction){
		new_x++;
	} else {
		new_x--;
	}
	ok_move = enemy.move(new_x, enemy.get_y());
	if(!ok_move){
		if(flag_direction){
			new_x -= 2;
		} else {
			new_x += 2;
		}
		flag_direction = !flag_direction;
		enemy.move(new_x, enemy.get_y());
	}
}


