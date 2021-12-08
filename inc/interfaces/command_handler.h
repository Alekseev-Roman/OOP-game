#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <memory>

enum class Command{
	Up,
	Down,
	Left,
	Right
};

class Command_handler{
public:
	virtual ~Command_handler() = default;
	virtual void set_next(const std::shared_ptr<Command_handler>& command_handler) = 0;
	virtual void handle(Command command) = 0;
};

#endif // COMMAND_HANDLER_H
