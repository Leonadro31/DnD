#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "../../sdk/Widgets/include.h"

#include "../FightVisualizer/entities/Entity/Entity.h"

class Menu
{
private:
	sf::RenderWindow* m_window = nullptr;
	sf::Font* m_breathefire_font = nullptr;
	sf::Sprite m_background;
	sf::Texture m_background_texture;
	std::string* m_current_tab;

	std::vector<Button*> m_buttons;

	Entity* ent;

	bool m_first_load = true;

	void m_load_widgets();
	void m_load_background();
	void m_events_handler();

	void m_callback() { std::cout << "Callback\n"; }
public:
	bool* is_running;

	Menu(sf::RenderWindow* window, sf::Font* breathefire_font, bool* is_running, std::string* current_tab);
	~Menu();

	void call_on_load();
	void main();
};

