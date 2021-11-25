#ifndef FINISH_CELL_H
#define FINISH_CELL_H

#include "cell.h"
#include "../interfaces/game_i.h"

class Finish_cell: public Cell{
public:
	Finish_cell(Game_i& game_object);
	void check_player() const;

private:
	Game_i& game;
};

#endif // FINISH_CELL_H
