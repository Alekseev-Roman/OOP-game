#ifndef HANDLER_SFML_H
#define HANDLER_SFML_H

#include "../../interfaces/handler.h"

#include <map>
#include <SFML/Graphics.hpp>

class Handler_SFML: public Handler{
public:
	Handler_SFML(const std::shared_ptr<sf::RenderWindow>& w);
	void set_next(const std::shared_ptr<Command_handler>& c_handler);
	void process_command();

private:
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<Command_handler> command_handler;
	std::map<sf::Keyboard::Key, Command> keys = {
		{sf::Keyboard::W, Command::Up},
		{sf::Keyboard::S, Command::Down},
		{sf::Keyboard::A, Command::Left},
		{sf::Keyboard::D, Command::Right},
		{sf::Keyboard::Up, Command::Up},
		{sf::Keyboard::Down, Command::Down},
		{sf::Keyboard::Left, Command::Left},
		{sf::Keyboard::Right, Command::Right}
	};
};

#endif // HANDLER_SFML_H
