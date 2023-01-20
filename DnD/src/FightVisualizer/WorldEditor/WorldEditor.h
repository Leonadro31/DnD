#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "../../Globals.h"

#include "../../../sdk/entities/Tile/Tile.h"

#include "../../../sdk/Widgets/include.h"



class WorldEditor
{
private:

	sf::Vector2f m_position;
	sf::Sprite m_grid;
	sf::Texture m_grid_texture;
	sf::RectangleShape m_selected_marker;

	std::vector<Tile*> m_tiles;

	bool m_first_load = true;
	bool m_draw_grid = false;
	int m_selected_tile_type = 0;

	RoundCheckBox* m_grid_checkbox = new RoundCheckBox(sf::Vector2f(1100, 750), 10, &m_draw_grid);
	sf::Text m_grid_text;

	void m_call_on_load();
public:
	WorldEditor(const sf::Vector2f& position);
	~WorldEditor();

	inline int get_selected_type() { return m_selected_tile_type; }
	void clear_selection() { m_selected_tile_type = 0; }
	void check_click(const sf::Vector2i& mouse_pos);
	void draw(sf::RenderWindow* render_window);
};

