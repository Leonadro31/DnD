#include "GenericEntity.h"


GenericEntity::GenericEntity(const std::string& texture_path, const sf::Vector2f& position, const sf::Vector2f& size) {
	m_marker.setRadius(5.f);
	m_marker.setFillColor(sf::Color::Red);

	this->set_texture(texture_path);

	m_position = position;
	m_size = size;

	this->set_size(m_size);
	this->set_position(position);
	m_center_marker();
}

GenericEntity::~GenericEntity() {

}

void GenericEntity::m_center_marker() {
	sf::FloatRect marker_rect = m_marker.getLocalBounds();
	m_marker.setOrigin(marker_rect.left + marker_rect.width / 2.0f, marker_rect.top);
	m_marker.setPosition(sf::Vector2f(m_position.x + m_size.x / 2, m_position.y - marker_rect.height - 5));
}

void GenericEntity::set_position(const sf::Vector2f& position) {
	/*if (m_texture == nullptr || m_sprite == nullptr) {
		std::cout << "[-] Entity Texture or Sprite is nullptr" << std::endl;
		return;
	}
	*/
	m_position = position;
	m_sprite.setPosition(m_position);
	m_center_marker();
}


void GenericEntity::set_size(const sf::Vector2f& size) {
	m_size = size;
	sf::FloatRect sprite_size = m_sprite.getGlobalBounds();
	m_sprite.setScale(sf::Vector2f(size.x / sprite_size.width, size.y / sprite_size.height));
}


void GenericEntity::set_texture(const std::string& texture_path) {
	if (!m_texture.loadFromFile(texture_path)) std::cout << "[-] Couldn't load texture: " << texture_path << std::endl;
	m_sprite.setTexture(m_texture);
}


void GenericEntity::check_click(const sf::Vector2i& mouse_pos) {
	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_size.x) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_size.y)) {
		std::cout << "[Debug] Entity clicked." << std::endl;
		m_is_selected = !m_is_selected;
		return;
	}
	std::cout << "[Debug] Entity not clicked." << std::endl;
	m_is_selected = false;
}


void GenericEntity::draw(sf::RenderWindow* window) {
	window->draw(m_sprite);
	window->draw(m_marker);
}


