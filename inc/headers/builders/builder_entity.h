#ifndef BUILDER_ENTITY_H
#define BUILDER_ENTITY_H

#include "../../interfaces/game_i.h"

#include "../../interfaces/command_handler.h"

#include "../logger/logger_terminal.h"
#include "../logger/logger_file.h"
#include "../../interfaces/logger.h"

#include "../field.h"
#include "../painter_SFML.h"

#include "../strategies/horizontal_strategy.h"
#include "../strategies/vertical_strategy.h"

#include "../enemies/slime.h"
#include "../enemies/parasite.h"
#include "../enemies/infected_astronaut.h"

#include "../enemies/player.h"

#include "../../../textures.txt"

#include <set>

class Builder_entity{
public:
	Builder_entity();
	std::set<std::shared_ptr<Cell_element>> create_enemy(Field& field, std::shared_ptr<Painter_SFML> paint, std::shared_ptr<Painter> painter,
		std::set<std::shared_ptr<Cell_element>> objects_game,  Game_i& game);
	std::set<std::shared_ptr<Cell_element>> create_player(Field& field, std::shared_ptr<Painter_SFML> paint, std::shared_ptr<Painter> painter,
		std::set<std::shared_ptr<Logger>> loggers, std::set<std::shared_ptr<Cell_element>> objects_game,  Game_i& game, std::shared_ptr<Command_handler>& c_handler);
};

#endif // BUILDER_ENTITY_H
