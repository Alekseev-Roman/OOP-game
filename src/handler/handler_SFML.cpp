#include "../../inc/headers/handler/handler_SFML.h"
#include <iostream>

Handler_SFML::Handler_SFML(const std::shared_ptr<sf::RenderWindow>& w):
	window{w} {}

void Handler_SFML::set_next(const std::shared_ptr<Command_handler>& c_handler){
	command_handler = c_handler;
}

void Handler_SFML::process_command(){
	sf::Event event;
	while(window->pollEvent(event)){
		if (event.type == sf::Event::Closed){
            window->close();
            break;
        }
		if(event.type != sf::Event::KeyPressed){
			continue;
		} else {
		}
		auto command_key = keys[event.key.code];
		if(command_handler)
			command_handler->handle(command_key);
	};
}
