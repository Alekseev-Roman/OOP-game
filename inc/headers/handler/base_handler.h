#ifndef BASE_HANDLER_H
#define BASE_HANDLER_H

#include "../../interfaces/command_handler.h"

class Base_handler: public Command_handler{
public:
	void set_next(const std::shared_ptr<Command_handler>& n_handler);

protected:
	std::shared_ptr<Command_handler> next_handler;

};

#endif // BASE_HANDLER_H
