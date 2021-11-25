#ifndef BOOSTER_H
#define BOOSTER_H

#include "attackable_entity.h"

class Attackable_entity;

class Booster{
public:
	virtual ~Booster() = default;
	virtual void effect(Attackable_entity& entity) = 0;
};

#endif // BOOSTER_H
