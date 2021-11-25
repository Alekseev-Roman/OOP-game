#ifndef GAME_I_H
#define GAME_I_H

#include "../headers/painter_SFML.h"

class Game_i{
public:
	virtual void start() = 0;
	virtual Cell& get_cell(int pos_x, int pos_y) const = 0;
	virtual void odject_destroyed(const Cell_element& cell_element) = 0;
	virtual void creater(std::shared_ptr<Painter_SFML> paint) = 0;
	virtual size_t check_pass() const = 0;
	virtual size_t check_killed_enemies() const = 0;
	virtual void add_pass() = 0;
	virtual void add_killed_enemies() = 0;
	virtual void finish() = 0;
	
};

#endif // GAME_I_H
