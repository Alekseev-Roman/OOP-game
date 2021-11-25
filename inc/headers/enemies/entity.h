#ifndef ENTITY_H
#define ENTITY_H

#include "../movable_element.h"
#include "../signals/signal_fight.h"
#include "../signals/signal_take.h"
#include "../../interfaces/attackable_entity.h"

class Entity: public Attackable_entity, public Movable_element{
public:
	Entity(int pos_x, int pos_y, int default_health, int default_armor, int default_damage, Game_i& game_object);

	void change_health(int coeff_change_health);
	void change_damage(int coeff_change_damage);
	void change_armor(int coeff_change_armor);
	int get_health() const;
	int get_armor() const;
	int get_damage() const;

	bool interaction(Cell_element& item);
	bool interaction(Attackable_entity& item);
	bool interaction(Booster& item);

	void attack(Attackable_entity& entity);

private:
	int health;
	int damage;
	int armor;

protected:
	bool attack_flag = false;
};

#endif // ENTITY_H
