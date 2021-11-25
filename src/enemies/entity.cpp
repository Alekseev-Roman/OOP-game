#include "../../inc/headers/enemies/entity.h"

Entity::Entity(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object):
	Movable_element::Movable_element(pos_x, pos_y, game_object), health(default_health), armor(default_armor), damage(default_damage){}


void Entity::change_health(int coeff_change_health){
	health += coeff_change_health;
	if(health <= 0){
		destroy();
	}
}

void Entity::change_damage(int coeff_change_damage){
	health += coeff_change_damage;
}

void Entity::change_armor(int coeff_change_armor){
	health += coeff_change_armor;
}

int Entity::get_health() const{
	return health;
}

int Entity::get_armor() const{
	return armor;
}

int Entity::get_damage() const{
	return damage;
}

bool Entity::interaction(Cell_element& item){
	return item.interaction((Attackable_entity&)*this);
}

bool Entity::interaction(Attackable_entity& item){
	if(item.check_attack() != attack_flag){
		attack(item);
		return true;
	}
	return false;
}

bool Entity::interaction(Booster& item){
	if(check_take_item()){
		item.effect(*this);
		signal_send(Signal_take(*this));
		return true;
	}
	return false;
}

void Entity::attack(Attackable_entity& entity){
	int delta = get_damage() - entity.get_armor(); 
	if(delta < 0)
		delta = 0;
	signal_send(Signal_fight(*this, delta));
	entity.change_health(-delta);
}
