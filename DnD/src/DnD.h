#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#ifdef _WIN64
#include <Windows.h>
#endif

#include "../sdk/Widgets/include.h"

#include "FightVisualizer/FightVisualizer.h"
#include "Menu/Menu.h"
#include "CharacterSheet/CharacterSheet.h"
#include "CharacterSheet/NewSheet/NewSheet.h"
#include "CharacterSheet/NewSheet/NewSheet2.h"
#include "CharacterSheet/LoadSheet/LoadSheet.h"


#include "Globals.h"

using namespace sf;

class DnD
{
private:
	bool m_is_running = true;
	
	RenderWindow* m_window;
	int m_width, m_height;
	
	std::map<std::string, Font*> m_fonts;

	std::vector<TextInput*> m_input_boxes;
	std::vector<Button*> m_buttons;
	std::vector<RoundCheckBox*> m_round_check_boxes;
	std::vector<SquareCheckBox*> m_square_check_boxes;

	sf::Sprite* m_background = nullptr;
	sf::Texture* m_background_texture = nullptr;

	std::string m_current_tab = "Menu";

	Menu* m_menu = nullptr;
	FightVisualizer* m_fight_visualizer = nullptr;
	CharacterSheet* m_character_sheet = nullptr;
	NewSheet* m_new_sheet = nullptr;
	NewSheet2* m_new_sheet_2 = nullptr;
	LoadSheet* m_load_sheet = nullptr;
	

	void m_load_fonts();

public:
	


	DnD(int width, int height, const char* title);
	DnD(int width, int height, int fps, const char* title);
	~DnD();

	std::string get_current_tab() { return m_current_tab; }
	void set_current_tab(std::string& tab) { m_current_tab = tab; }

	RenderWindow* get_render_window() { return m_window; }
	std::map<std::string, Font*>* get_fonts() { return &m_fonts; }

	void exit() { m_is_running = false; }
	void main();
};

