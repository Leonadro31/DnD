#include "DnD.h"


DnD::DnD(int width, int height, const char* title) {
	m_window = new RenderWindow(VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);
	m_width = width;
	m_height = height;
	m_window->setFramerateLimit(60);
}


DnD::DnD(int width, int height, int fps, const char* title) {
	m_window = new RenderWindow(VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close);
	m_width = width;
	m_height = height;
	m_window->setFramerateLimit(fps);
}


DnD::~DnD() {
	for (const auto& square_check_box : m_square_check_boxes) delete square_check_box;
	for (const auto& round_check_box : m_round_check_boxes) delete  round_check_box;
	for (const auto& text_input : m_input_boxes) delete text_input;
	for (const auto& button : m_buttons) delete button;
	for (const auto& font : m_fonts) delete font.second;
	delete m_background;
	delete m_background_texture;
}

/*
void DnD::events_handler() {
	Event event;
	bool is_caps = false;
	while (m_window->pollEvent(event))
	{
		
		if (event.type == Event::Closed)
		{
			m_window->close();
			this->is_running = false;
		}

#pragma region mouse
		if (event.type == Event::MouseButtonReleased) {
			sf::Vector2i mouse_pos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
			std::cout << "[Debug] Click Pos: (" << mouse_pos.x << ", " << mouse_pos.y << ")" << std::endl;

			for (const auto& square_check_box : m_square_check_boxes) square_check_box->check_click(mouse_pos);
			for (const auto& round_check_box : m_round_check_boxes) round_check_box->check_click(mouse_pos);
			for (const auto& text_input : m_input_boxes) text_input->check_click(mouse_pos);
			for (const auto& button : m_buttons) button->check_click(mouse_pos);

		}

#pragma endregion


#pragma region keyboard
		if (event.type == Event::KeyPressed) {
			
		}
		
		if (event.type == Event::KeyReleased) {
		//	std::cout << "[Debug] Key: " << event.text.unicode << std::endl;

			if (event.text.unicode == 4294967295) {
				//caps lock
			}

			if (event.text.unicode < 25) {
				char pressed_letter = static_cast<char>(event.text.unicode + 0x41);;
				
				if (is_caps && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);
				if (!is_caps && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);
		
				for (TextInput* input_box : m_input_boxes) {
					input_box->get_input(pressed_letter);
				}
			}
			else if (event.text.unicode == 57) {
				for (TextInput* input_box : m_input_boxes) {
					input_box->get_input(' ');
				}
			}
			else if (26 <= event.text.unicode && event.text.unicode <= 35) {
				int pressed_number = event.text.unicode - 26;
				for (TextInput* input_box : m_input_boxes) {
					input_box->get_input(pressed_number);
				}
			}
			else if (event.text.unicode == 59) {
				for (TextInput* input_box : m_input_boxes) {
					input_box->get_input(true);
				}
			}
			else {
				std::cout << "[Debug] Key: " << event.text.unicode << std::endl;
			}
			
			
			
		}
#pragma endregion
	}
}
*/


void DnD::m_load_fonts() {
	Font* arial = new Font();
	Font* breathefire = new Font();

	if (arial->loadFromFile(globals::get_assets_path("arial.ttf"))) std::cout << "[+] Loaded Arial font." << std::endl;
	else std::cout << "[-] Couldn't load Arial font." << std::endl;

	if (breathefire->loadFromFile(globals::get_assets_path("BreatheFire.ttf"))) std::cout << "[+] Loaded BreatheFire font." << std::endl;
	else std::cout << "[-] Couldn't load BreatheFire font." << std::endl;

	m_fonts.insert({ "Arial", arial });
	m_fonts.insert({ "BreatheFire", breathefire });


}


void DnD::main() {
	m_load_fonts();

	m_menu = new Menu(m_window, m_fonts["BreatheFire"], &m_is_running, &m_current_tab);
	m_fight_visualizer = new FightVisualizer(&m_fonts, &m_is_running, &m_current_tab);
	m_character_sheet = new CharacterSheet(&m_fonts, &m_is_running, &m_current_tab);
	m_new_sheet = new NewSheet(&m_fonts, &m_is_running, &m_current_tab);
	m_new_sheet_2 =new NewSheet2(&m_fonts, &m_is_running, &m_current_tab, &m_new_sheet->m_stats);
	m_load_sheet = new LoadSheet(&m_fonts, &m_is_running, &m_current_tab);

	while (m_is_running) {
		if (m_current_tab == "Menu") m_menu->main();
		else if (m_current_tab == "FightVisualizer") m_fight_visualizer->main();
		else if (m_current_tab == "CharacterSheet") m_character_sheet->main();
		else if (m_current_tab == "NewSheet") m_new_sheet->main();
		else if (m_current_tab == "NewSheet2") m_new_sheet_2->main();
		else if (m_current_tab == "LoadSheet") m_load_sheet->main();
		
	}

}