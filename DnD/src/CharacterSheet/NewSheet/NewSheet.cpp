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


	for (const auto& button : m_buttons) {
		button->set_font_size(20);
	}
}

void NewSheet::call_on_load() {
	m_window = new sf::RenderWindow(sf::VideoMode(960, 540), "DnD - Nuova Sheda", sf::Style::Titlebar | sf::Style::Close);
	m_background_texture.loadFromFile("C:\\Users\\39348\\source\\repos\\DnD\\DnD\\assets\\NewSheetBg.jpg");
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


	m_window->display();


}
