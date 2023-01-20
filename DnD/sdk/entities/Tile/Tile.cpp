#include "Tile.h"


Tile::Tile(int type, int row, int col) : GenericEntity(m_get_path_from_type(type), m_get_position_from_coords(row, col), sf::Vector2f(40.f, 40.f)) {
	this->type = type;
	this->row = row;
	this->col = col;
}

Tile::Tile(int type, const sf::Vector2f& position) : GenericEntity(m_get_path_from_type(type), position, sf::Vector2f(60.f, 60.f)) {
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
#ifdef DEBUG_ENTITIES
		std::cout << "[Debug] Entity clicked." << std::endl;
#endif
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
	std::string base = globals::get_assets_path("tiles\\");
	switch (type)
	{
	case 1:
		return base + "grass.png";
		break;
	case 2:
		return base + "water.png";
		break;
	case 3:
		return base + "stone.png";
		break;
	case 4:
		return base + "dark_stone.png";
		break;
	case 5:
		return base + "dark_grass.png";
		break;
	case 6:
		return base + "lava.png";
		break;
	case 7:
		return base + "acid.png";
		break;
	case 8:
		return base + "parquet.png";
		break;
	case 9:
		return base + "stone_bricks.png";
		break;
	case 10:
		return base + "dark_water.png";
		break;
	default:
		return base + "grass.png";
		break;
	}
}