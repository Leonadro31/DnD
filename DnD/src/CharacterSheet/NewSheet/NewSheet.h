#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "C:\\Users\\39348\\source\\repos\\DnD\\DnD\\sdk\\Widgets\\include.h"

struct Stats {
	std::string Classe;
	std::string Razza;
	std::string BackGround;

	bool m_ability_check_acrobazia= false;
	bool m_ability_check_animali = false;
	bool m_ability_check_arcana = false;
	bool m_ability_check_atletica = false;
	bool m_ability_check_furtività = false;
	bool m_ability_check_indagare = false;
	bool m_ability_check_inganno = false;
	bool m_ability_check_intimidire = false;
	bool m_ability_check_intrattenere = false;
	bool m_ability_check_intuizione = false;
	bool m_ability_check_medicina = false;
	bool m_ability_check_natura = false;
	bool m_ability_check_percezione = false;
	bool m_ability_check_persuasione = false;
	bool m_ability_check_rapidità = false;
	bool m_ability_check_religione = false;
	bool m_ability_check_sopravvivenza = false;
	bool m_ability_check_storia = false;

	bool m_sav_throw_str = false;
	bool m_sav_throw_dex = false;
	bool m_sav_throw_con = false;
	bool m_sav_throw_int = false;
	bool m_sav_throw_wis = false;
	bool m_sav_throw_cha = false;



	int Str;
	int Dex;
	int Con;
	int Int;
	int Wis;
	int Cha;
	int Lvl;
};

class NewSheet
{
private:
	sf::Sprite m_background;
	sf::Texture m_background_texture;
	sf::RenderWindow* m_window;
	sf::Font* m_breathfire_font = nullptr;
	
	Stats m_stats;

	std::string* m_current_tab;
	std::map < std::string, sf::Font*>* m_fonts;
	std::vector<Button*> m_buttons;
	std::vector<TextInput*> m_text_input;
	std::vector<RoundCheckBox*> m_round_check_box;

	bool* m_is_running;
	bool m_first_load = true;
	

    void m_event_handler();
	void m_load_widgets();

public:
	NewSheet(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab);
	~NewSheet();

	void call_on_load();

	void main();
};