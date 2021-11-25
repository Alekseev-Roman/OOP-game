#include "../../inc/headers/builders/builder_boosters.h"

Builder_boosters::Builder_boosters(){}

std::set<std::shared_ptr<Cell_element>> Builder_boosters::create(Field& field, std::shared_ptr<Painter_SFML> paint, std::shared_ptr<Painter> painter, std::set<std::shared_ptr<Cell_element>>  objects_game, Game_i& game){
	auto healer_first = std::make_shared<Healer_booster>(0, 5, 25, game);
	painter->set_element(HEALER_TEXTURE, *healer_first);
	healer_first->subscribe(paint);
	game.get_cell(0, 5).set_element(healer_first);
	objects_game.insert(healer_first);

	auto healer_second = std::make_shared<Healer_booster>(14, 2, 25, game);
	painter->set_element(HEALER_TEXTURE, *healer_second);
	healer_second->subscribe(paint);
	game.get_cell(13, 0).set_element(healer_second);
	objects_game.insert(healer_second);

	auto armor_first = std::make_shared<Healer_booster>(5, 9, 25, game);
	painter->set_element(ARMOR_TEXTURE, *armor_first);
	armor_first->subscribe(paint);
	game.get_cell(5, 9).set_element(armor_first);
	objects_game.insert(armor_first);

	auto damage_first = std::make_shared<Healer_booster>(3, 0, 25, game);
	painter->set_element(DAMAGE_TEXTURE, *damage_first);
	damage_first->subscribe(paint);
	game.get_cell(9, 5).set_element(damage_first);
	objects_game.insert(damage_first);

	auto damage_second = std::make_shared<Healer_booster>(9, 5, 25, game);
	painter->set_element(DAMAGE_TEXTURE, *damage_second);
	damage_second->subscribe(paint);
	game.get_cell(9, 5).set_element(damage_second);
	objects_game.insert(damage_second);

	auto pass = std::make_shared<Pass>(0, 2, game);
	painter->set_element(PASS_TEXTURE, *pass);
	pass->subscribe(paint);
	game.get_cell(0, 2).set_element(pass);
	objects_game.insert(pass);

	return objects_game;
}
