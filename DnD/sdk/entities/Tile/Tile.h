#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "../GenericEntity.h"
#include "../../../src/Globals.h"
class Tile : public GenericEntity
{
private:


	void m_center_marker() override;
	std::string m_get_path_from_type(int type);
	sf::Vector2f m_get_position_from_coords(int row, int col) {return sf::Vector2f(297 + col * 40, 19 + row * 40);}
	
public:
	Tile(int type, int row, int col);
	Tile(int type, const sf::Vector2f& position);
	~Tile();

	int type = 0;
	int row, col;

	inline sf::Vector2f get_position() { return m_position; }
	void check_click(const sf::Vector2i& mouse_pos) override;
};

