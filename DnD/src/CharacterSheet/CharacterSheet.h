#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "../../sdk/Widgets/include.h"

#include "../FightVisualizer/entities/Entity/Entity.h"
#include "../Globals.h"

class CharacterSheet
{
private:
	sf::Sprite m_background;
	sf::Texture m_background_texture;
	sf::RenderWindow* m_window;
	sf::Font* m_breathfire_font = nullptr;
	
	std::string* m_current_tab;
	std::map < std::string, sf::Font*>* m_fonts;
	std::vector<Button*> m_buttons;
	
	bool* m_is_running;
	bool m_first_load = true;
	
	void m_events_handler();
	void m_load_widgets();
public:
	CharacterSheet(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab);
	~CharacterSheet();

	void call_on_load();
	
	void main();
};



