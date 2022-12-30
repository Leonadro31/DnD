#include "FightVisualizer.h"


FightVisualizer::FightVisualizer(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab) {
	m_fonts = fonts;
	m_is_running = is_running;
	m_current_tab = current_tab;
}


FightVisualizer::~FightVisualizer() {
	for (const auto& entity : m_entities) delete entity;
	delete m_fonts;
	delete m_is_running;
	delete m_current_tab;
	delete m_window;
}


void FightVisualizer::m_load_widgets() {
	for (auto& tile_row : m_tiles) for (auto& tile : tile_row) delete tile;
}

void FightVisualizer::m_load_tiles() {
	for (int row = 0; row < 19; row++) {
		std::vector<Tile*> row_vec;
		for (int col = 0; col < 19; col++) {
			row_vec.push_back(new Tile(1, row, col));
		}
		m_tiles.push_back(row_vec);
	}
}

void FightVisualizer::m_load_background() {
	if (!m_background_texture.loadFromFile("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\fight_visualizer_bg.png")) std::cout << "[-] Couldn't load FightVisualizer background texture." << std::endl;
	m_background.setTexture(m_background_texture);
}

void FightVisualizer::call_on_load() {
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 800), "DnD - Fight Visualizer", sf::Style::Titlebar | sf::Style::Close);
	m_load_widgets();
	m_load_background();
	m_load_tiles();
	m_entities.push_back(new Entity("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\werewolf.png", sf::Vector2f(695.f,380.f), sf::Vector2f(100, 100), 100));
}

void FightVisualizer::m_events_handler() {
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
			for (const auto& entity : m_entities) entity->check_click(mouse_pos);

			for (const auto& tile_row : m_tiles) {
				for (const auto& tile : tile_row) {
					tile->check_click(mouse_pos);
				}
			}
			
		}


	}
}


void FightVisualizer::main() {
	if (m_first_load) {
		this->call_on_load();
		m_first_load = false;
	}
	m_events_handler();

	m_window->clear(sf::Color::White);

	m_window->draw(m_background);
	for (auto& tile_row : m_tiles) for (auto& tile : tile_row) tile->draw(m_window);
	for (const auto& entity : m_entities) entity->draw(m_window);
	
	m_window->display();
}