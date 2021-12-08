#ifndef PAINTER_SFML_H
#define PAINTER_SFML_H

#include <SFML/Graphics.hpp>
#include "../interfaces/painter.h"
#include "signals/basic_signal_input.h"
#include <iostream>

class Painter_SFML:public Painter, public Basic_signal_input{
public:
	Painter_SFML(int height_window, int width_window, const std::shared_ptr<sf::RenderWindow>& w);
	void set_field(const Field& field);
	void paint_cell(const std::string& cell_texture, int x, int y);
	sf::Texture& get_texture(const std::string& name_texture);
	void paint_window();
	bool check_window();
	void signal_move(Cell_element& element, int new_x, int new_y);
	void signal_fight(Cell_element& element, int coeff_damage){}
	void signal_take(Cell_element& element){}
	void signal_destroy(Cell_element& element);
	void set_element(const std::string& texture, Cell_element& element);

private:
	void paint_cell_elements();
	void paint_field();

	using sprite_ptr = std::unique_ptr<sf::Sprite[]>;
	using sprite_ptr_ptr = std::unique_ptr<sprite_ptr[]>;
	sprite_ptr_ptr arr_sprite;
	std::shared_ptr<sf::RenderWindow> window;
	int height;
	int width;
	int side_cell;
	int height_field;
	int width_field;
	std::map<std::string, sf::Texture> textures;
	std::map<size_t, sf::Sprite> sprites;
};

#endif // PAINTER_SFML_H
