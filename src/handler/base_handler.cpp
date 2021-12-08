#include "../../inc/headers/handler/base_handler.h"

void Base_handler::set_next(const std::shared_ptr<Command_handler>& n_handler){
	next_handler = n_handler;
}