#ifndef GAME_H
#define GAME_H

#include "../interfaces/game_i.h"
#include "field.h"
#include "../interfaces/painter.h"
#include "../interfaces/logger.h"
#include "logger/logger_terminal.h"
#include "logger/logger_file.h"
#include "../interfaces/logger.h"
#include "painter_SFML.h"
#include "builders/builder_fields.h"
#include "builders/builder_entity.h"
#include "builders/builder_boosters.h"

#include <ctime>
#include <set>
#include <chrono>
#include <iostream>

template <typename... Rules>
class Game: public Game_i{
public:
	Game();
	void start();
	Cell& get_cell(int pos_x, int pos_y) const;
	void odject_destroyed(const Cell_element& cell_element);
	void creater(std::shared_ptr<Painter_SFML> paint);
	size_t check_pass() const;
	size_t check_killed_enemies() const;
	void add_pass();
	void add_killed_enemies();
	void finish();
	
private:
	bool check_all_rules(Rules... args) const;
	Field field;
	std::shared_ptr<Painter> painter;
	std::set<std::shared_ptr<Cell_element>> objects_game;
	std::set<std::shared_ptr<Logger>> loggers;
	size_t passes = 0;
	size_t killed_enemies = 0;
};

template <typename... Rules>
Game<Rules...>::Game():
	field(10, 15){
		auto paint = std::make_shared<Painter_SFML>(650, 975, "Game");
		painter = paint;
		painter->set_field(field);

		auto logger_terminal = std::make_shared<Logger_terminal>();
		auto logger_first_file = std::make_shared<Logger_file>("../log.txt");

		loggers.insert(logger_terminal);
		loggers.insert(logger_first_file);

		creater(paint);
	}

template <typename... Rules>
void Game<Rules...>::start(){
	std::chrono::duration<double> diff_seconds;
    auto stamp = std::chrono::steady_clock::now();
    auto cur = stamp;
	while(painter->check_window()){
    	stamp = std::chrono::steady_clock::now();
    	for (auto& obj : objects_game) {        
    	    obj->update();
    	}

        do {                   
            painter->paint_window();
    	    cur = std::chrono::steady_clock::now();
        	diff_seconds = cur - stamp;
        } while (diff_seconds.count() < 1.5);		
	}
}

template <typename... Rules>
Cell& Game<Rules...>::get_cell(int pos_x, int pos_y) const{
	return field.get_cell(pos_x, pos_y);
}

template <typename... Rules>
void Game<Rules...>::odject_destroyed(const Cell_element& cell_element){
	for (auto iter = objects_game.begin(); iter != objects_game.end(); ++iter){
        if ((*iter).get() == &cell_element){
            objects_game.erase(iter);
            return;
        }
	}
}

template <typename... Rules>
void Game<Rules...>::creater(std::shared_ptr<Painter_SFML> paint){
	Builder_fields builder_f;
	field = builder_f.create(field, painter, *this);

	Builder_entity builder_e;
	objects_game = builder_e.create_player(field, paint, painter, loggers, objects_game, *this);
	objects_game = builder_e.create_enemy(field, paint, painter, objects_game, *this);

	Builder_boosters  builder_b;
	objects_game = builder_b.create(field, paint, painter, objects_game, *this);
}

template <typename... Rules>
size_t Game<Rules...>::check_pass() const{
	return passes;
}

template <typename... Rules>
size_t Game<Rules...>::check_killed_enemies() const{
	return killed_enemies;
}

template <typename... Rules>
void Game<Rules...>::add_pass(){
	passes++;
}

template <typename... Rules>
void Game<Rules...>::add_killed_enemies(){
	killed_enemies++;
}

template <typename... Rules>
bool Game<Rules...>::check_all_rules(Rules... args) const{
	return (... && args.checker(*this));
}

template <typename... Rules>
void Game<Rules...>::finish(){
	if(check_all_rules(Rules{}...)){
		std::cout << "Finish" << std::endl;
	}
}

#endif // GAME_H
