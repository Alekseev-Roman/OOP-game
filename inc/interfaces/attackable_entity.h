#ifndef ATTACKABLE_ENTITY_H
#define ATTACKABLE_ENTITY_H

class Attackable_entity{
public:
	virtual ~Attackable_entity() = default;
	virtual void change_health(int coeff_change_health) = 0;
	virtual void change_damage(int coeff_change_damage) = 0;
	virtual void change_armor(int coeff_change_armor) = 0;
	virtual	int get_health() const = 0;
	virtual int get_armor() const = 0;
	virtual int get_damage() const = 0;
	virtual bool check_take_item() const = 0;
	virtual bool check_attack() const = 0;
	virtual void attack(Attackable_entity& entity) = 0;
};

#endif // ATTACKABLE_ENTITY_H
