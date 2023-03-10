#include "Entity.h"


Entity::Entity(const std::string& texture_path, const sf::Vector2f& position, const sf::Vector2f& size, int health_points) : GenericEntity(texture_path, position, size) {
	m_health = health_points;
#ifdef DEBUG_ENTITIES
	std::cout << "[Debug] Entity created." << std::endl;
#endif
}

Entity::~Entity() {
#ifdef DEBUG_ENTITIES
	std::cout << "[Debug] Entity destructed." << std::endl;
#endif
}


void Entity::check_click(const sf::Vector2i& mouse_pos) {
	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_size.x) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_size.y)) {
#ifdef DEBUG_ENTITIES
		std::cout << "[Debug] Entity clicked." << std::endl;
#endif
		m_is_selected = !m_is_selected;
		return;
	}
	if (m_is_selected) {
		if ((mouse_pos.x >= 300 && mouse_pos.x <= 1050) && (mouse_pos.y >= 20 && mouse_pos.y <= 780)) this->set_position(sf::Vector2f(mouse_pos.x - m_size.x / 2.f, mouse_pos.y - m_size.y / 2.f));
	}
	m_is_selected = false;
}

void Entity::draw(sf::RenderWindow* window) {
	if (m_health > 0) {
		window->draw(m_sprite);
		if (m_is_selected) window->draw(m_marker);
	}

}