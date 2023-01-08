#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\sdk\\Widgets\\include.h"
#include "..\..\Globals.h"

class LoadSheet
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


	void m_event_handler();
	void m_load_widgets();

public:
	LoadSheet(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab);
	~LoadSheet();

	void call_on_load();

	void main();
};
