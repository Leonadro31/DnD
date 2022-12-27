#include "DnD.h"


DnD::DnD(int width, int height, const char* title) {
	m_window = new RenderWindow(VideoMode(width, height), title);
	m_width = width;
	m_height = height;
	m_window->setFramerateLimit(60);
}


DnD::DnD(int width, int height, int fps, const char* title) {
	m_window = new RenderWindow(VideoMode(width, height), title);
	m_width = width;
	m_height = height;
	m_window->setFramerateLimit(fps);
}


DnD::~DnD() {
	for (TextInput* input_box : input_boxes) {
		delete input_box;
	}
}

inline void callback() {
	std::cout << "[Callback Test]\n";
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

		if (event.type == Event::MouseButtonReleased) {
			sf::Vector2i mouse_pos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
			std::cout << "[Debug] Click Pos: (" << mouse_pos.x << ", " << mouse_pos.y << ")" << std::endl;

			for (TextInput* input_box : input_boxes) {
				input_box->check_click(mouse_pos);
			}
			button->check_click(mouse_pos);
		}

		if (event.type == Event::KeyPressed) {
			
		}
		
		if (event.type == Event::KeyReleased) {
//			std::cout << "[Debug] Key: " << event.text.unicode << std::endl;

			if (event.text.unicode == 4294967295) {
				//caps lock
			}

			if (event.text.unicode < 25) {
				char pressed_letter = static_cast<char>(event.text.unicode + 0x41);;
				
				if (is_caps && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);
				if (!is_caps && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);
		
				for (TextInput* input_box : input_boxes) {
					input_box->get_input(pressed_letter);
				}
			}
			else if (26 <= event.text.unicode && event.text.unicode <= 35) {
				int pressed_number = event.text.unicode - 26;
				for (TextInput* input_box : input_boxes) {
					input_box->get_input(pressed_number);
				}
			}
			else if (event.text.unicode == 59) {
				for (TextInput* input_box : input_boxes) {
					input_box->get_input(true);
				}
			}
			else {
				std::cout << "[Debug] Key: " << event.text.unicode << std::endl;
			}
			
			
			
		}

	}
}


void DnD::main() {

	sf::Font font;
	if (!font.loadFromFile("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\arial.ttf"))
	{
		std::cout << "[-] Couldn't load font." << std::endl;
	}

	
	input_boxes.push_back(new TextInput(font, Vector2f(100.f, 100.f), Vector2f(100.0, 40.f), "test"));
	button = new Button(font, Vector2f(100.f, 200.f), Vector2f(100.0, 40.f), "test2", &callback);
	button->set_clicked_border_color(sf::Color(47, 49, 51, 255));
	button->set_clicked_background_color(sf::Color(68, 115, 135, 255));

	while (this->is_running) {
		events_handler();
		
		m_window->clear(Color(59, 156, 150));
		
		for (TextInput* input_box : input_boxes) {
			input_box->draw(m_window);
		}
		button->draw(m_window);

		m_window->display();
	}

}