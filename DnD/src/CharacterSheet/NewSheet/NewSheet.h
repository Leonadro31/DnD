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


#include "C:\\Users\\39348\\source\\repos\\DnD\\DnD\sdk\Widgets\\include.h"
#include "..\..\Globals.h"

class TextBox
{
private:
	sf::Text* m_text;
	sf::RectangleShape* m_background;
	sf::RectangleShape* m_line;
	sf::Vector2f m_position, m_size;
	std::string m_placeholder;
	sf::Color m_background_fill_color, m_background_border_color;
	float m_background_border_thickness = 3.f;

	int line_animation_count = 0;

	void m_center_text_in_rect();
public:
	bool is_selected = false;

	TextBox(sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder);
	TextBox(sf::Font& font, const sf::Color& color, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder);
	~TextBox();

	void draw(sf::RenderWindow* window);
	void get_input(char character);
	void get_input(bool backspace);
	void get_input(int number);
	std::string get_text() { return m_placeholder; }
	bool check_click(const sf::Vector2i& mouse_pos);
	void set_position(const sf::Vector2f& position);
	void set_font_size(int size);
	void set_background_fill_color(const sf::Color& color);
	void set_background_border_color(const sf::Color& color);
	void set_background_border_thickness(float thickness);
	void m_update_text(const std::string& output) {
		m_text->setString(output);
		m_center_text_in_rect();
	}

	sf::Text* get_text_object() { return m_text; }
	sf::RectangleShape* get_background_object() { return m_background; }
};

struct Stats {
	std::string Classe;
	std::string Livello;
	std::string Razza;
	std::string BackGround;
	std::string Bonus;
	std::string Forza;
	std::string Destrezza;
	std::string Costituzione;
	std::string Intelligenza;
	std::string Saggeza;
	std::string Carisma;
	std::string ModFor;
	std::string ModDes;
	std::string ModCos;
	std::string ModInt;
	std::string ModSag;
	std::string ModCar;

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

	int m_bonus=2;
	int m_lvl;



	int Str;
	int Dex;
	int Con;
	int Int;
	int Wis;
	int Cha;
	int StrMod = (Str / 2) - 5;
	int DexMod = (Dex / 2) - 5;
	int ConMod = (Con / 2) - 5;
	int IntMod = (Int / 2) - 5;
	int WisMod = (Wis / 2) - 5;
	int ChaMod = (Cha / 2) - 5;
};

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
