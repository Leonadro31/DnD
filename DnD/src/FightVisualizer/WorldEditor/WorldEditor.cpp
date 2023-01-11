#include "WorldEditor.h"


WorldEditor::WorldEditor(const sf::Vector2f& position) {
	m_position = position;

	if (!m_grid_texture.loadFromFile("C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\visualizer_grid.png")) std::cout << "[-] Couldn't load FightVisualizer grid texture." << std::endl;
	m_grid.setTexture(m_grid_texture);
	m_grid.setPosition(sf::Vector2f(297.f, 19.f));
}

WorldEditor::~WorldEditor() {
	delete m_grid_checkbox;
}

void WorldEditor::m_call_on_load() {
	m_selected_marker.setOutlineColor(sf::Color::Red);
	m_selected_marker.setFillColor(sf::Color(0, 0, 0, 0));
	m_selected_marker.setOutlineThickness(2);
	m_selected_marker.setSize(sf::Vector2f(60, 60));
	

	for (int i = 1; i < TILE_TYPES + 1; i++) {
		if (i % 2 == 0) {
			m_tiles.push_back(new Tile(i, sf::Vector2f(m_position.x + 80, m_position.y + 75 * ((i-1) / 2))));
		}
		else {
			m_tiles.push_back(new Tile(i, sf::Vector2f(m_position.x, m_position.y + 75 * (i/2))));
		}

	}
}


void WorldEditor::check_click(const sf::Vector2i& mouse_pos) {
	if ((mouse_pos.x >= 1050 || mouse_pos.x <= 300)) {
		m_selected_tile_type = 0;
	}

	m_grid_checkbox->check_click(mouse_pos);

	for (const auto& tile : m_tiles) {
		tile->check_click(mouse_pos);
		if (tile->is_selected()) {
			m_selected_tile_type = tile->type;
			m_selected_marker.setPosition(tile->get_position());
			std::cout << "[Debug] Selected tile type: " << m_selected_tile_type << "\n";
		} 
	}

}

void WorldEditor::draw(sf::RenderWindow* render_window) {
	if (m_first_load) {
		m_first_load = false;
		m_call_on_load();
	}

	if (m_draw_grid) render_window->draw(m_grid);

	for (Tile* tile : m_tiles) {
		tile->draw(render_window);
	}

	m_grid_checkbox->draw(render_window);
	if (m_selected_tile_type != 0) render_window->draw(m_selected_marker);
}