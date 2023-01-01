#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "entities/GenericEntity.h"
#include "entities/Entity/Entity.h"
#include "entities/Tile/Tile.h"
#include "entities/WorldEntity/WorldEntity.h"


class FightVisualizer
{

private:
	sf::RenderWindow* m_window = nullptr;
	sf::RenderWindow* m_win = nullptr;
	sf::Sprite m_background;
	sf::Texture m_background_texture;

	sf::Sprite m_grid;
	sf::Texture m_grid_texture;

	std::map<std::string, sf::Font*>* m_fonts = nullptr;

	std::vector<std::vector<Tile*>> m_tiles; //19x19 tiles, 20x20 each

	std::vector<GenericEntity*> m_entities;

	bool* m_is_running;
	std::string* m_current_tab;

	bool m_first_load = true;

	void m_events_handler();
	void m_load_widgets();
	void m_load_textures();
	void m_load_tiles();
public:
	FightVisualizer(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab);
	~FightVisualizer();

	void call_on_load();
	void main();
};

