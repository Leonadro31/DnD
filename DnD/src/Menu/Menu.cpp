#include "Menu.h"


Menu::Menu(sf::RenderWindow* window, sf::Font* breathefire_font, bool* is_running, std::string* current_tab) {
	m_window = window;
	m_breathefire_font = breathefire_font;
	m_current_tab = current_tab;
	this->is_running = is_running;


}


Menu::~Menu() {
	for (const auto& button : m_buttons) delete button;
	delete m_window;
	delete m_breathefire_font;
	delete m_current_tab;
}


void Menu::m_load_widgets() {
	if (m_breathefire_font == nullptr) std::cout << "[-] BreatheFire font is nullptr" << std::endl;

	m_buttons.push_back(new Button("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\button.png", *m_breathefire_font, sf::Vector2f(138.f, 70.f), sf::Vector2f(210.0, 40.f), "Schede Personaggio", 0));
	m_buttons.push_back(new Button("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\button.png", *m_breathefire_font, sf::Vector2f(138.f, 130.f), sf::Vector2f(210.0, 40.f), "Visualizzatore Fights", 0));


	for (const auto& button : m_buttons) {
		button->set_font_size(20);
	}
}

void Menu::m_load_background() {
	if (m_background_texture.loadFromFile("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\menu.png")) std::cout << "[+] Loaded background image." << std::endl;
	else {
		std::cout << "[-] Couldn't load background image." << std::endl;
		return;
	}
	m_background.setTexture(m_background_texture);
}


void Menu::call_on_load() {
	m_load_widgets();
	m_load_background();
}

void Menu::m_events_handler() {
	sf::Event event;
	bool is_caps = false;
	while (m_window->pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
		{
			m_window->close();
			*this->is_running = false;
		}


		if (event.type == sf::Event::MouseButtonReleased) {
			sf::Vector2i mouse_pos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
			std::cout << "[Debug] Click Pos: (" << mouse_pos.x << ", " << mouse_pos.y << ")" << std::endl;

			if (m_buttons[0]->check_click(mouse_pos)) {
				*m_current_tab = "SheetBuilder";
				m_first_load = true;
			}

			if (m_buttons[1]->check_click(mouse_pos)) {
				*m_current_tab = "FightVisualizer";
				m_window->close();
				m_first_load = true;
			}

		}


	}
}


void Menu::main() {
	if (m_first_load) {
		this->call_on_load();
		m_first_load = false;
	}

	m_events_handler();

	m_window->clear(sf::Color::Black);

	m_window->draw(m_background);

	for (const auto& button : m_buttons) button->draw(m_window);


	m_window->display();
}
