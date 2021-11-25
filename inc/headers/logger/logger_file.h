#ifndef LOGGER_FILE_H
#define LOGGER_FILE_H

#include "../../interfaces/logger.h"
#include "../signals/basic_signal_input.h"
#include "../../interfaces/cell_element.h"

#include <iostream>
#include <fstream>
#include <map>

class Logger_file: public Logger{
public:
	Logger_file(std::string name_file = "../log.txt");
	~Logger_file();
	void signal_move(Cell_element& element, int new_x, int new_y);
	void signal_fight(Cell_element& element, int coeff_damage);
	void signal_take(Cell_element& element);
	void signal_destroy(Cell_element& element);
	void change_log_file(std::string new_name_file);

private:
	std::ofstream file_log;
	std::string name_file_log;
};

#endif // LOGGER_FILE_H
