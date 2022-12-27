#include "RoundCheckBox.h"


RoundCheckBox::RoundCheckBox(const sf::Vector2f& position, float radius, bool* buffer) {
	m_circle = new sf::CircleShape();
	m_inner_circle = new sf::CircleShape();

	m_position = position;
	m_radius = radius;
	m_buffer = buffer;
	m_outline_thickness = m_radius / 5;

	m_inner_circle_color = sf::Color(132, 182, 209, 255);
	m_inner_circle_radius = m_radius * 0.72;

	m_background_color = sf::Color(224, 224, 224, 180);
	m_outline_color = sf::Color(74, 74, 74, 180);

	m_inner_circle->setRadius(m_inner_circle_radius);
	m_inner_circle->setFillColor(m_inner_circle_color);

	m_circle->setRadius(m_radius);
	m_circle->setFillColor(m_background_color);
	m_circle->setOutlineColor(m_outline_color);
	m_circle->setOutlineThickness(m_outline_thickness);
	m_circle->setPosition(m_position);

	m_center_inner_circle();
}


RoundCheckBox::~RoundCheckBox() {
	delete m_circle;
	delete m_inner_circle;
}


void RoundCheckBox::m_center_inner_circle() {
	sf::FloatRect inner_circle_rect = m_inner_circle->getGlobalBounds();
	m_inner_circle->setOrigin(inner_circle_rect.left + inner_circle_rect.width / 2.0f, inner_circle_rect.top + inner_circle_rect.height / 2.0f);
	m_inner_circle->setPosition(sf::Vector2f(m_position.x + m_radius, m_position.y + m_radius));
}


void RoundCheckBox::set_position(const sf::Vector2f position) {
	m_position = position;
	m_circle->setPosition(m_position);
	m_center_inner_circle();
}


void RoundCheckBox::set_background_color(const sf::Color& color) {
	m_background_color = color;
	m_circle->setFillColor(m_background_color);
}


void RoundCheckBox::set_outline_color(const sf::Color& color) {
	m_outline_color = color;
	m_circle->setOutlineColor(m_outline_color);
}


void RoundCheckBox::set_checked_color(const sf::Color& color) {
	m_inner_circle_color = color;
	m_inner_circle->setFillColor(m_inner_circle_color);
}


void RoundCheckBox::set_outline_thickness(float thickness) {
	m_outline_thickness = thickness;
	m_circle->setOutlineThickness(m_outline_thickness);
}




void RoundCheckBox::draw(sf::RenderWindow* window) {
	window->draw(*m_circle);
	if (*m_buffer) window->draw(*m_inner_circle);
}

void RoundCheckBox::check_click(const sf::Vector2i& mouse_pos) {
	
	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_radius*2) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_radius*2)) {
		std::cout << "[Debug] CheckBox clicked." << std::endl;
		*m_buffer = !*m_buffer;
	}
}
