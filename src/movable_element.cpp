#include "../inc/headers/movable_element.h"

bool Movable_element::move(int pos_x, int pos_y){
	auto& cell = game.get_cell(pos_x, pos_y);
    if(pos_x == get_x() && pos_y == get_y()){
        return true;
    }
    if(cell.check_wall()){
        return false;
    }
    if(cell.check_element()){
        if (!cell.get_element()->interaction(*this)) {
            return false;
        }
    }
    if(!cell.check_element()){
        auto& current = game.get_cell(get_x(), get_y());
        signal_send(Signal_move(*this, pos_x, pos_y));       
        cell.set_element(current.get_element());
        current.set_element(nullptr);
        x = pos_x;
        y = pos_y;
    }
    return true;
}
