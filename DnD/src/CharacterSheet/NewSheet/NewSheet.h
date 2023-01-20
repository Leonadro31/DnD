#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

#ifdef _WIN64
#include <Windows.h>
#endif


#include "..\..\..\sdk\Widgets\include.h"
#include "..\..\Globals.h"
#include "../../../sdk/entities/Entity/Stats.h"




class NewSheet
{
private:
	sf::Sprite m_background;
	sf::Texture m_background_texture;
	sf::RenderWindow* m_window;
	sf::Font* m_breathfire_font = nullptr;
	
	

	std::string* m_current_tab;
	std::map < std::string, sf::Font*>* m_fonts;
	std::vector<Button*> m_buttons;
	std::vector<TextInput*> m_text_input;
	std::vector<RoundCheckBox*> m_round_check_box;
	std::vector<TextBox*> m_text_output;

	bool* m_is_running;
	bool m_first_load = true;
	

    void m_event_handler();
	void m_load_widgets();
	void m_load_text_box();

public:
	NewSheet(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab);
	~NewSheet();
	
	Stats m_stats;
	
	void call_on_load();

	void main();
};
