#include "NewSheet.h"

NewSheet::NewSheet(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab) {
	m_fonts = fonts;
	m_is_running = is_running;
	m_current_tab = current_tab;
}

NewSheet::~NewSheet() {
	delete m_fonts;
	delete m_is_running;
	delete m_current_tab;
}

void NewSheet::m_load_widgets() {

	m_buttons.push_back(new Button("C:\\Users\\39348\\source\\repos\\DnD\\DnD\\assets\\button.png", *m_fonts->at("BreatheFire"), sf::Vector2f(0.f, 0.f), sf::Vector2f(40.0, 40.f), "<-", 0));
	
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(69.f, 114.f), sf::Vector2f(240.0, 40.f), "")); //nome pg
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(518.f, 90.f), sf::Vector2f(210.0, 20.f), "")); // classe e lvl
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(754.f, 90.f), sf::Vector2f(170.0, 20.f), "")); // background
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(952.f, 90.f), sf::Vector2f(170.0, 20.f), "")); //nome player
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(518.f, 145.f), sf::Vector2f(210.0, 20.f), "")); //razza
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(754.f, 145.f), sf::Vector2f(170.0, 20.f), "")); // allineamento
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(952.f, 145.f), sf::Vector2f(170.0, 20.f), "")); //exp
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(44.f, 301.f), sf::Vector2f(55.0, 55.f), "")); //Forza
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(180.f, 300.f), sf::Vector2f(55.0, 55.f), "")); //Intelligenza
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(44.f, 450.f), sf::Vector2f(55.0, 55.f), "")); //dex
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(180.f, 449.f), sf::Vector2f(55.0, 55.f), "")); //wis
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(44.f, 598.f), sf::Vector2f(55.0, 55.f), "")); //con
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(180.f, 598.f), sf::Vector2f(55.0, 55.f), "")); //cha
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(303.f, 265.f), sf::Vector2f(34.0, 34.f), "")); //Ispirazione
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(846.f, 285.f), sf::Vector2f(45.0, 45.f), "")); //Ispirazione

	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f,269.f),6, &m_stats.m_ability_check_acrobazia)); //acrobazia
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 297.f),6, &m_stats.m_ability_check_animali)); //addestrare animali
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 325.f), 6, &m_stats.m_ability_check_arcana));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 353.f), 6, &m_stats.m_ability_check_atletica));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 381.f), 6, &m_stats.m_ability_check_furtività));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 409.f), 6, &m_stats.m_ability_check_indagare));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 438.f), 6, &m_stats.m_ability_check_inganno));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 466.f), 6, &m_stats.m_ability_check_intimidire));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 494.f), 6, &m_stats.m_ability_check_intrattenere));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 522.f), 6, &m_stats.m_ability_check_intuizione));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 550.f), 6, &m_stats.m_ability_check_medicina));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 578.f), 6, &m_stats.m_ability_check_natura));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 606.f), 6, &m_stats.m_ability_check_percezione));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 634.f), 6, &m_stats.m_ability_check_persuasione));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 662.f), 6, &m_stats.m_ability_check_rapidità));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 690.f), 6, &m_stats.m_ability_check_religione));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 718.f), 6, &m_stats.m_ability_check_sopravvivenza));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 746.f), 6, &m_stats.m_ability_check_storia));

	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 431.f), 6, &m_stats.m_sav_throw_str));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 459.f), 6, &m_stats.m_sav_throw_dex));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 487.f), 6, &m_stats.m_sav_throw_con));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 515.f), 6, &m_stats.m_sav_throw_int));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 543.f), 6, &m_stats.m_sav_throw_wis));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 571.f), 6, &m_stats.m_sav_throw_cha));

	for (const auto& button : m_buttons) {
		button->set_font_size(20);
	}

	for (const auto& textinput : m_text_input) {
		textinput->set_background_fill_color(sf::Color(0, 0, 0, 0));
		textinput->set_background_border_color(sf::Color(0, 0, 0, 0));
	}
}

void NewSheet::call_on_load() {
	m_window = new sf::RenderWindow(sf::VideoMode(1200, 840), "DnD - Nuova Sheda", sf::Style::Titlebar | sf::Style::Close);
	m_background_texture.loadFromFile("C:\\Users\\39348\\source\\repos\\DnD\\DnD\\assets\\CharacterSheet.png");
	m_background.setTexture(m_background_texture);

	m_load_widgets();
}

void NewSheet::m_event_handler() {
	sf::Event event;
	bool is_caps = false;
	while (m_window->pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
		{
			m_window->close();
			*this->m_is_running = false;
		}

		if (event.type == sf::Event::MouseButtonReleased) {
			sf::Vector2i mouse_pos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
			std::cout << "[Debug] Click Pos: (" << mouse_pos.x << ", " << mouse_pos.y << ")" << std::endl;

			for (const auto& button : m_buttons) button->check_click(mouse_pos);

			if (m_buttons[0]->check_click(mouse_pos)) {
				*m_current_tab = "CharacterSheet";
				m_first_load = true;
				m_window->close();
			}

			for (const auto& textinput : m_text_input) textinput->check_click(mouse_pos);
			for (const auto& round_check : m_round_check_box) round_check->check_click(mouse_pos);
		}

		if (event.type == sf::Event::KeyPressed) {

		}

		if (event.type == sf::Event::KeyReleased) {
			//	std::cout << "[Debug] Key: " << event.text.unicode << std::endl;

			if (event.text.unicode == 4294967295) {
				//caps lock
			}

			if (event.text.unicode <= 25) {
				char pressed_letter = static_cast<char>(event.text.unicode + 0x41);;

				if (is_caps && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);
				if (!is_caps && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);

				for (TextInput* input_box : m_text_input) {
					input_box->get_input(pressed_letter);
				}
			}
			else if (event.text.unicode == 57) {
				for (TextInput* input_box : m_text_input) {
					input_box->get_input(' ');
				}
			}
			else if (26 <= event.text.unicode && event.text.unicode <= 35) {
				int pressed_number = event.text.unicode - 26;
				for (TextInput* input_box : m_text_input) {
					input_box->get_input(pressed_number);
				}
			}
			else if (event.text.unicode == 59) {
				for (TextInput* input_box : m_text_input) {
					input_box->get_input(true);
				}
			}
			else {
				std::cout << "[Debug] Key: " << event.text.unicode << std::endl;
			}



		}
	}
}


void NewSheet::main() {
	if (m_first_load) {
		call_on_load();
		m_first_load = false;
	}

	m_event_handler();

	m_window->clear(sf::Color::Black);
	m_window->draw(m_background);
	
	for (const auto& button : m_buttons) button->draw(m_window);
	for (const auto& text : m_text_input) text->draw(m_window);
	for (const auto& round_check : m_round_check_box) round_check->draw(m_window);


	m_window->display();


}
