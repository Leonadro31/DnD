#include "Entity.h"


Entity::Entity(const std::string& texture_path, const sf::Vector2f& position, const sf::Vector2f& size, int health_points) : GenericEntity(texture_path, position, size) {
	m_health = health_points;
	std::cout << "[Debug] Entity created." << std::endl;
}

Entity::~Entity() {
	std::cout << "[Debug] Entity destructed." << std::endl;
}


void Entity::draw(sf::RenderWindow* window) {
	if (m_health > 0) {
		window->draw(*m_sprite);
	}
}