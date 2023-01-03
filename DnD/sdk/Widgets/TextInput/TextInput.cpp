#include "TextInput.h"



TextInput::TextInput(sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder) {
	m_text = new sf::Text();
	m_background = new sf::RectangleShape();
	m_line = new sf::RectangleShape();

	m_text->setFont(font);
	m_text->setFillColor(sf::Color::Black);
	m_text->setString(placeholder);

	m_background->setPosition(position);
	m_background->setSize(size);
	m_background->setFillColor(sf::Color(71, 121, 143, 255));
	m_background->setOutlineColor(sf::Color(68, 104, 120, 255));
	m_background->setOutlineThickness(3);

	m_line->setPosition(sf::Vector2f(position.x, position.y + size.y));
	m_line->setSize(sf::Vector2f(size.x, m_background_border_thickness));
	m_line->setFillColor(sf::Color::Black);

	m_position = position;
	m_size = size;
	m_placeholder = placeholder;
	m_background_border_color = sf::Color(68, 104, 120, 255);
	m_background_fill_color = sf::Color(71, 121, 143, 255);
	m_background_border_thickness = 3.f;
	
	m_center_text_in_rect();

	std::cout << "[Debug] Created TextInput" << std::endl;
}

TextInput::TextInput(sf::Font& font, const sf::Color& color, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder) {
	m_text = new sf::Text();
	m_background = new sf::RectangleShape();
	m_line = new sf::RectangleShape();

	m_text->setFont(font);
	m_text->setFillColor(color);
	m_text->setString(placeholder);

	m_background->setPosition(position);
	m_background->setSize(size);
	m_background->setFillColor(sf::Color::White);
	m_background->setOutlineColor(sf::Color::Black);
	m_background->setOutlineThickness(5);
	
	m_line->setPosition(sf::Vector2f(position.x, position.y + size.y));
	m_line->setSize(sf::Vector2f(size.x, m_background_border_thickness));
	m_line->setFillColor(sf::Color::Black);

	m_position = position;
	m_size = size;
	m_placeholder = placeholder;
	m_background_border_color = sf::Color(68, 104, 120, 255);
	m_background_fill_color = sf::Color(71, 121, 143, 255);
	m_background_border_thickness = 3.f;

	m_center_text_in_rect();

	std::cout << "[Debug] Created TextInput" << std::endl;

}

TextInput::~TextInput() {
	std::cout << "[Debug] Deleting TextInput" << std::endl;
	delete m_text;
	delete m_background;
	delete m_line;
}


void TextInput::m_center_text_in_rect() {
	sf::FloatRect text_rect = m_text->getLocalBounds();
	m_text->setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
	m_text->setPosition(sf::Vector2f(m_position.x + m_size.x / 2, m_position.y + m_size.y / 2));
}


void TextInput::draw(sf::RenderWindow* win) {
	win->draw(*m_background);
	win->draw(*m_text);

	if (is_selected) {
		line_animation_count++;
		if (line_animation_count < 180) m_line->setFillColor(sf::Color::Black);
		else if (line_animation_count < 360) m_line->setFillColor(m_background_border_color);
		else line_animation_count = 0;
		win->draw(*m_line);
	}

}


bool TextInput::check_click(const sf::Vector2i& mouse_pos) {
	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_size.x) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_size.y)) {
		is_selected = true;
		std::cout << "[Debug] TextInput Selected" << std::endl;
		return true;
	}
	is_selected = false;
	return false;
}


void TextInput::get_input(char character) {
	if (!is_selected) return;

	m_placeholder.push_back(character);
	m_text->setString(m_placeholder);
	if (m_text->getLocalBounds().width > m_size.x) {
		m_placeholder.pop_back();
		m_text->setString(m_placeholder);
	}
	else {
		m_text->setString(m_placeholder);
		m_center_text_in_rect();
	}
}

void TextInput::get_input(int number) {
	if (!is_selected) return;

	m_placeholder += std::to_string(number);
	m_text->setString(m_placeholder);
	if (m_text->getLocalBounds().width > m_size.x) {
		m_placeholder.pop_back();
		m_text->setString(m_placeholder);
	}
	else {
		m_text->setString(m_placeholder);
		m_center_text_in_rect();
	}
}


void TextInput::get_input(bool backspace) {
	if (!is_selected) return;
	if (m_placeholder.length() <= 0) return;

	m_placeholder.pop_back();
	m_text->setString(m_placeholder);	
	m_text->setString(m_placeholder);
	m_center_text_in_rect();
}


void TextInput::set_position(const sf::Vector2f& position) {
	m_position = position;
	m_text->setPosition(m_position);
}

void TextInput::set_font_size(int size) {
	m_text->setCharacterSize(size);
	m_center_text_in_rect();
}

void TextInput::set_background_fill_color(const sf::Color& color) {
	m_background_fill_color = color;
	m_background->setFillColor(m_background_fill_color);
}


void TextInput::set_background_border_color(const sf::Color& color) {
	m_background_border_color = color;
	m_background->setOutlineColor(m_background_border_color);
}


void TextInput::set_background_border_thickness(float thickness) {
	m_background_border_thickness = thickness;
	m_background->setOutlineThickness(m_background_border_thickness);
}


