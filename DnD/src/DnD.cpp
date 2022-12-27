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

void DnD::m_load_widgets() {
	

	m_buttons = {
		new Button("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\button.png", *m_fonts["BreatheFire"], Vector2f(138.f, 70.f), Vector2f(210.0, 40.f), "Make New Sheet", 0),
		new Button("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\button.png", *m_fonts["BreatheFire"], Vector2f(138.f, 130.f), Vector2f(210.0, 40.f), "Load Old Sheet", 0)
	};

	for (const auto& button : m_buttons) {
		button->set_font_size(20);
	}
}

void DnD::m_load_background() {
	m_background_texture = new sf::Texture();
	m_background = new sf::Sprite();
	if (m_background_texture->loadFromFile("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\menu.png")) std::cout << "[+] Loaded background image." << std::endl;
	else {
		std::cout << "[-] Couldn't load background image." << std::endl;
		delete m_background;
		delete m_background_texture;
		return;
	}
	m_background->setTexture(*m_background_texture);
}

void DnD::m_load_fonts() {
	Font* arial = new Font();
	Font* breathefire = new Font();

	if (arial->loadFromFile("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\arial.ttf")) std::cout << "[+] Loaded arial font." << std::endl;
	else std::cout << "[-] Couldn't load arial font." << std::endl;

	if (breathefire->loadFromFile("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\BreatheFire.ttf")) std::cout << "[+] Loaded BreatheFire font." << std::endl;
	else std::cout << "[-] Couldn't load BreatheFire font." << std::endl;

	m_fonts.insert({ "Arial", arial });
	m_fonts.insert({ "BreatheFire", breathefire });


}


void DnD::main() {
	m_load_fonts();
	m_load_background();
	m_load_widgets();

	while (this->is_running) {
		events_handler();
		
		m_window->clear(Color(185, 187, 206, 255));
		
		m_window->draw(*m_background);
		
		for (const auto& square_check_box : m_square_check_boxes) square_check_box->draw(m_window);
		for (const auto& round_check_box : m_round_check_boxes) round_check_box->draw(m_window);
		for (const auto& text_input : m_input_boxes) text_input->draw(m_window);
		for (auto& button : m_buttons) button->draw(m_window);


		m_window->display();
	}

}