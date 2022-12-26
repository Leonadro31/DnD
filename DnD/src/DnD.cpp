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
	//Clean up
}

void DnD::events_handler() {
	Event event;
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
			input->check_click(mouse_pos);
		}

		if (event.type == Event::KeyPressed) {

		}
		
		if (event.type == Event::KeyReleased) {
			std::cout << "[Debug] Key: " << event.text.unicode << std::endl;
			if (event.text.unicode < 25) {
				char pressed_letter = static_cast<char>(event.text.unicode + 0x41);
				input->get_input(pressed_letter);
			}
			if (26 <= event.text.unicode <= 35) {
				int pressed_number = event.text.unicode - 26;
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

	input = new TextInput(font, Vector2f(100.f, 1.f), Vector2f(100.0, 30.f), "test");


	while (this->is_running) {
		events_handler();
		
		m_window->clear(Color(59, 156, 150));
		
		input->draw(m_window);


		m_window->display();
	}

}