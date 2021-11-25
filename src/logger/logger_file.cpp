#include "../../inc/headers/logger/logger_file.h"
#include "../../inc/headers/logger/operators.h"
#include <cstdlib>

Logger_file::Logger_file(std::string name_file){
	name_file_log = name_file;
	std::ofstream new_file_log(name_file_log);
	file_log = move(new_file_log);
	file_log << "File log started" << std::endl;
}

Logger_file::~Logger_file(){
	file_log << "File log finished" << std::endl;
	file_log.close();
}

void Logger_file::signal_move(Cell_element& element, int new_x, int new_y){
	file_log << element << " moved to (" << new_x << "; " << new_y << ")" << std::endl;
}

void Logger_file::signal_fight(Cell_element& element, int coeff_damage){
	file_log << element << " fight: coeff_damage =  " << coeff_damage << std::endl;
}

void Logger_file::signal_take(Cell_element& element){
	file_log << element << " take booster" << std::endl;
}

void Logger_file::signal_destroy(Cell_element& element){
	file_log << element << " dead" << std::endl;
}

void Logger_file::change_log_file(std::string new_name_file){
	file_log.close();
	name_file_log = new_name_file;
	std::ofstream file_log(name_file_log);
	file_log << "File log started" << std::endl;
}



