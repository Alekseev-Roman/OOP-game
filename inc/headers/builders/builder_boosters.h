#ifndef BUILDER_BOOSTERS_H
#define BUILDER_BOOSTERS_H

#include "../../interfaces/game_i.h"

#include "../field.h"
#include "../painter_SFML.h"

#include "../boosters/healer_booster.h"
#include "../boosters/armor_booster.h"
#include "../boosters/damage_booster.h"
#include "../boosters/pass.h"

#include "../../../textures.txt"

class Builder_boosters{
public:
	Builder_boosters();
	std::set<std::shared_ptr<Cell_element>> create(Field& field, std::shared_ptr<Painter_SFML> paint, std::shared_ptr<Painter> painter, std::set<std::shared_ptr<Cell_element>>  objects_game, Game_i& game);
};

#endif // BUILDER_BOOSTERS_H