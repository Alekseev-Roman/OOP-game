#include "../../inc/headers/logger/logger_terminal.h"
#include "../../inc/headers/logger/operators.h"
#include <cstdlib>

Logger_terminal::Logger_terminal(){
	std::cout << "Terminal log started" << std::endl;
}

Logger_terminal::~Logger_terminal(){
	std::cout << "Terminal log finished" << std::endl;
}

void Logger_terminal::signal_move(Cell_element& element, int new_x, int new_y){
	std::cout << element << " moved to (" << new_x << "; " << new_y << ")" << std::endl;
}

void Logger_terminal::signal_fight(Cell_element& element, int coeff_damage){
	std::cout << element << " fight: coeff_damage =  " << coeff_damage << std::endl;
}

void Logger_terminal::signal_take(Cell_element& element){
	std::cout << element << " take booster" << std::endl;
}

void Logger_terminal::signal_destroy(Cell_element& element){
	std::cout << element << " dead" << std::endl;
}



