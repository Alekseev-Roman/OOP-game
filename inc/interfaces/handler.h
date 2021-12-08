#ifndef HANDLER_H
#define HANDLER_H

#include "command_handler.h"

class Handler{
public:
	virtual ~Handler() = default;
	virtual void set_next(const std::shared_ptr<Command_handler>& command_handler) = 0;
	virtual void process_command() = 0;
};

#endif // HANDLER_H
