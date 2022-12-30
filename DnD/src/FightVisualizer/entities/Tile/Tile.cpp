#include "Tile.h"


Tile::Tile(int type, int row, int col) : GenericEntity(m_get_path_from_type(type), m_get_position_from_coords(row, col), sf::Vector2f(40.f, 40.f)) {
	this->type = type;
}


Tile::~Tile() {

}


void Tile::m_center_marker() {
	sf::FloatRect marker_rect = m_marker.getLocalBounds();
	m_marker.setOrigin(marker_rect.left + marker_rect.width / 2.0f, marker_rect.top + marker_rect.height / 2.f);
	m_marker.setPosition(sf::Vector2f(m_position.x + m_size.x / 2.f, m_position.y + m_size.y / 2.f));
}

void Tile::check_click(const sf::Vector2i& mouse_pos) {
	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_size.x) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_size.y)) {
		std::cout << "[Debug] Entity clicked." << std::endl;
		m_is_selected = !m_is_selected;
		return;
	}
	if (m_is_selected) {
	//	std::cout << mouse_pos.x << " " << mouse_pos.y << std::endl;
		//this->set_position(sf::Vector2f(mouse_pos.x - m_size.x / 2.f, mouse_pos.y - m_size.y / 2.f));
	}
	m_is_selected = false;
}

std::string Tile::m_get_path_from_type(int type) {
	std::string base = "C:\\Users\\Leonardo\\source\\repos\\DnD\\DnD\\assets\\tiles\\";
	switch (type)
	{
	case 1:
		return base + "grass.png";
	case 2:
		return base + "water.png";
	case 3:
		return base + "stone.png";
	default:
		break;
	}
}