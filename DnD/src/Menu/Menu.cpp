#include "Menu.h"


Menu::Menu(sf::RenderWindow* window, sf::Font* breathefire_font, bool* is_running, std::string* current_tab) {
	m_window = window;
	m_breathefire_font = breathefire_font;
	m_current_tab = current_tab;
	this->is_running = is_running;

	m_load_widgets();
	m_load_background();
}


Menu::~Menu() {
	for (const auto& button : m_buttons) delete button;
	delete m_window;
	delete m_breathefire_font;
	delete m_background;
	delete m_background_texture;
	delete m_current_tab;
}


void Menu::m_load_widgets() {
	if (m_breathefire_font == nullptr) std::cout << "[-] BreatheFire font is nullptr" << std::endl;

	m_buttons = {
		new Button("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\button.png", *m_breathefire_font, sf::Vector2f(138.f, 70.f), sf::Vector2f(210.0, 40.f), "Make New Sheet", 0),
		new Button("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\button.png", *m_breathefire_font, sf::Vector2f(138.f, 130.f), sf::Vector2f(210.0, 40.f), "Load Old Sheet", 0)
	};

	for (const auto& button : m_buttons) {
		button->set_font_size(20);
	}
}

void Menu::m_load_background() {
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

			for (const auto& button : m_buttons) button->check_click(mouse_pos);

		}


	}
}


void Menu::main() {
	m_events_handler();

	m_window->clear(sf::Color::Black);

	m_window->draw(*m_background);

	for (auto& button : m_buttons) button->draw(m_window);

	generic_entity->draw(m_window);

	m_window->display();
}
