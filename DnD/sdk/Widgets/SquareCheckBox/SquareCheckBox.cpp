#include "SquareCheckBox.h"


SquareCheckBox::SquareCheckBox(const sf::Vector2f& position, float side, bool* buffer) {
	m_square = new sf::RectangleShape();
	m_inner_square = new sf::RectangleShape();

	m_position = position;
	m_side = side;
	m_buffer = buffer;
	m_outline_thickness = m_side / 5;

	m_inner_square_color = sf::Color(132, 182, 209, 255);
	m_inner_square_side = m_side * 0.72;

	m_background_color = sf::Color(224, 224, 224, 180);
	m_outline_color = sf::Color(74, 74, 74, 180);

	m_inner_square->setSize(sf::Vector2f(m_inner_square_side, m_inner_square_side));
	m_inner_square->setFillColor(m_inner_square_color);

	m_square->setSize(sf::Vector2f(m_side, m_side));
	m_square->setFillColor(m_background_color);
	m_square->setOutlineColor(m_outline_color);
	m_square->setOutlineThickness(m_outline_thickness);
	m_square->setPosition(m_position);

	m_center_inner_square();
}


SquareCheckBox::~SquareCheckBox() {
	delete m_square;
	delete m_inner_square;
}


void SquareCheckBox::m_center_inner_square() {
	sf::FloatRect inner_circle_rect = m_inner_square->getGlobalBounds();
	m_inner_square->setOrigin(inner_circle_rect.left + inner_circle_rect.width / 2.0f, inner_circle_rect.top + inner_circle_rect.height / 2.0f);
	m_inner_square->setPosition(sf::Vector2f(m_position.x + m_side/2.f, m_position.y + m_side/2.f));
}


void SquareCheckBox::set_position(const sf::Vector2f position) {
	m_position = position;
	m_square->setPosition(m_position);
	m_center_inner_square();
}


void SquareCheckBox::set_background_color(const sf::Color& color) {
	m_background_color = color;
	m_square->setFillColor(m_background_color);
}


void SquareCheckBox::set_outline_color(const sf::Color& color) {
	m_outline_color = color;
	m_square->setOutlineColor(m_outline_color);
}


void SquareCheckBox::set_checked_color(const sf::Color& color) {
	m_inner_square_color = color;
	m_inner_square->setFillColor(m_inner_square_color);
}


void SquareCheckBox::set_outline_thickness(float thickness) {
	m_outline_thickness = thickness;
	m_square->setOutlineThickness(m_outline_thickness);
}




void SquareCheckBox::draw(sf::RenderWindow* window) {
	window->draw(*m_square);
	if (*m_buffer) window->draw(*m_inner_square);
}

void SquareCheckBox::check_click(const sf::Vector2i& mouse_pos) {

	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_side) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_side)) {
		std::cout << "[Debug] CheckBox clicked." << std::endl;
		*m_buffer = !*m_buffer;
	}
}
