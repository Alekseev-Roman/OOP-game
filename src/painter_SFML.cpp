#include "../inc/headers/painter_SFML.h"


Painter_SFML::Painter_SFML(int height_window, int width_window, const std::shared_ptr<sf::RenderWindow>& w):
	height(height_window), width(width_window), window{w} {}

void Painter_SFML::set_field(const Field& field){
	height_field = field.get_height();
	width_field = field.get_width();
	side_cell = std::min(height/field.get_height(), width/field.get_width());
	arr_sprite = std::make_unique<sprite_ptr[]>(field.get_height());
	for(int i = 0; i < field.get_height(); i++){
		arr_sprite[i] = std::make_unique<sf::Sprite[]>(field.get_width());
		for(int e = 0; e < field.get_width(); e++){
			arr_sprite[i][e] = sf::Sprite();
			arr_sprite[i][e].setPosition(e*side_cell, i*side_cell);
		}
	}
}

void Painter_SFML::paint_cell(const std::string& cell_texture, int x, int y){
	sf::Texture& texture = get_texture(cell_texture);
	arr_sprite[y][x].setTexture(texture);
	arr_sprite[y][x].setScale((double)side_cell/texture.getSize().x, (double)side_cell/texture.getSize().y);
}

sf::Texture& Painter_SFML::get_texture(const std::string& name_texture){
	if (textures.find(name_texture) == textures.end()) {
           textures[name_texture].loadFromFile(name_texture);
    }
	return textures[name_texture];
}

void Painter_SFML::paint_window(){
	window->clear();
	paint_field();
	paint_cell_elements();
	window->display();
/*
	sf::Event event;
	while (window->pollEvent(event)){
    	if (event.type == sf::Event::Closed){
            window->close();
            break;
        }
	}*/
}

void Painter_SFML::paint_cell_elements(){
	for(auto& [key, val] : sprites){
        window->draw(val);
    }
}

void Painter_SFML::paint_field(){
	for(int i = 0; i < height_field; i++){
		for(int e = 0; e < width_field; e++){
			window->draw(arr_sprite[i][e]);
		}
	}
}

bool Painter_SFML::check_window(){
	return window->isOpen();
}

void Painter_SFML::signal_move(Cell_element& element, int new_x, int new_y){
	sprites[element.unique_number()].setPosition(arr_sprite[new_y][new_x].getPosition());
}

void Painter_SFML::signal_destroy(Cell_element& element){
	sprites.erase(element.unique_number());
}

void Painter_SFML::set_element(const std::string& texture, Cell_element& element){
	const auto& tex = get_texture(texture);
    auto pos_x = element.get_x();
    auto pos_y = element.get_y();
    sf::Sprite spr(tex);
    spr.setPosition(arr_sprite[pos_y][pos_x].getPosition());
    spr.setScale((double)side_cell/tex.getSize().x, (double)side_cell/tex.getSize().y);
    sprites[element.unique_number()] = spr;
}
