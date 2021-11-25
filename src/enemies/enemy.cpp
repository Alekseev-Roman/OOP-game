#include "../../inc/headers/enemies/enemy.h"

bool Enemy::check_take_item() const{
	return false;
}

void Enemy::update(){
	if(strategy)
		strategy->strategy_enemy(*this);
} 

void Enemy::set_strategy(std::unique_ptr<Strategy>&& new_strategy){
	strategy = std::move(new_strategy);
}

void Enemy::destroy(){
	game.add_killed_enemies();
	Entity::destroy();
}
