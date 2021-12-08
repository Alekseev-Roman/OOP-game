#include "../../inc/headers/builders/builder_entity.h"

Builder_entity::Builder_entity(){}

std::set<std::shared_ptr<Cell_element>> Builder_entity::create_enemy(Field& field, std::shared_ptr<Painter_SFML> paint, std::shared_ptr<Painter> painter, std::set<std::shared_ptr<Cell_element>>  objects_game, Game_i& game){
	auto slime_first = std::make_shared<Slime>(5, 0, 40, 0, 10, game);
	painter->set_element(SLIME_TEXTURE, *slime_first);
	slime_first->subscribe(paint);
	game.get_cell(5, 0).set_element(slime_first);
	slime_first->set_strategy(std::make_unique<Vertical_strategy>());
	objects_game.insert(slime_first);

	auto slime_second = std::make_shared<Slime>(9, 7, 40, 0, 10, game);
	painter->set_element(SLIME_TEXTURE, *slime_second);
	slime_second->subscribe(paint);
	game.get_cell(9, 7).set_element(slime_second);
	slime_second->set_strategy(std::make_unique<Horizontal_strategy>());
	objects_game.insert(slime_second);

	auto parasite_first = std::make_shared<Parasite>(10, 2, 60, 10, 15, game);
	painter->set_element(PARASITE_TEXTURE, *parasite_first);
	parasite_first->subscribe(paint);
	game.get_cell(3, 5).set_element(parasite_first);
	parasite_first->set_strategy(std::make_unique<Horizontal_strategy>());
	objects_game.insert(parasite_first);

	auto parasite_second = std::make_shared<Parasite>(3, 5, 60, 10, 15, game);
	painter->set_element(PARASITE_TEXTURE, *parasite_second);
	parasite_second->subscribe(paint);
	game.get_cell(10, 2).set_element(parasite_second);
	parasite_second->set_strategy(std::make_unique<Vertical_strategy>());
	objects_game.insert(parasite_second);

	auto astronaut_first = std::make_shared<Infected_astronaut>(1, 8, 100, 20, 20, game);
	painter->set_element(INFECTED_ASTRONAUT_TEXTURE, *astronaut_first);
	astronaut_first->subscribe(paint);
	game.get_cell(1, 8).set_element(astronaut_first);
	astronaut_first->set_strategy(std::make_unique<Vertical_strategy>());
	objects_game.insert(astronaut_first);

	auto astronaut_second = std::make_shared<Infected_astronaut>(13, 9, 100, 20, 20, game);
	painter->set_element(INFECTED_ASTRONAUT_TEXTURE, *astronaut_second);
	astronaut_second->subscribe(paint);
	game.get_cell(13, 9).set_element(astronaut_second);
	astronaut_second->set_strategy(std::make_unique<Vertical_strategy>());
	objects_game.insert(astronaut_second);

	return objects_game;
}

std::set<std::shared_ptr<Cell_element>> Builder_entity::create_player(Field& field, std::shared_ptr<Painter_SFML> paint, std::shared_ptr<Painter> painter,
	std::set<std::shared_ptr<Logger>> loggers, std::set<std::shared_ptr<Cell_element>>  objects_game, Game_i& game, std::shared_ptr<Command_handler>& c_handler){
	auto player = std::make_shared<Player>(0, 0, 100, 15, 100, game);
	painter->set_element(PLAYER_TEXTURE, *player);
	for(auto& log : loggers){        
        player->subscribe(log);
    }
	player->subscribe(paint);
	game.get_cell(0, 0).set_element(player);
	objects_game.insert(player);
	c_handler->set_next(player->get_command_handler());
	return objects_game;
}
