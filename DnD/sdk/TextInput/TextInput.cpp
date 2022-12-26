#include "TextInput.h"



TextInput::TextInput(sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder) {
	m_text = new sf::Text();
	m_background = new sf::RectangleShape();

	m_background->setPosition(position);
	m_background->setSize(size);
	m_background->setFillColor(sf::Color::White);
	m_background->setOutlineColor(sf::Color::Black);
	m_background->setOutlineThickness(5);

	m_text->setFont(font);
	m_text->setFillColor(sf::Color::Black);
	m_text->setString(placeholder);

	m_position = position;
	m_size = size;

	m_placeholder = placeholder;
	
	this->set_position(position);

	std::cout << "[Debug] Created TextInput" << std::endl;
}

TextInput::TextInput(sf::Font& font, const sf::Color& color, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder) {
	m_text = new sf::Text();
	m_background = new sf::RectangleShape();

	m_background->setPosition(position);
	m_background->setSize(size);
	m_background->setFillColor(sf::Color::White);
	m_background->setOutlineColor(sf::Color::Black);
	m_background->setOutlineThickness(5);

	m_text->setFont(font);
	m_text->setFillColor(color);
	m_text->setString(placeholder);
	
	m_position = position;
	m_size = size;

	m_placeholder = placeholder;

	this->set_position(position);

}

TextInput::~TextInput() {
	std::cout << "[Debug] Deleting TextInput" << std::endl;
	delete m_text;
	delete m_background;
}


void TextInput::draw(sf::RenderWindow* win) {
	win->draw(*m_background);
	win->draw(*m_text);
}


bool TextInput::check_click(const sf::Vector2i& mouse_pos) {
	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_size.x) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_size.y)) {
		is_selected = true;
		std::cout << "[Debug] TextInput Selected\n" << std::endl;
		return true;
	}
	is_selected = false;
	std::cout << "[Debug] TextInput Not Selected\n" << std::endl;
	return false;
}

void TextInput::get_input(char character) {
	if (!is_selected) return;

	m_placeholder.push_back(character);
	m_text->setString(m_placeholder);
	if (m_text->getGlobalBounds().width > m_size.x) {
		std::cout << "[Debug Warning] TextInput string is too long, cropping." << std::endl;
		m_placeholder.pop_back();
		m_text->setString(m_placeholder);
	}
	else {
		std::cout << "[Debug] TextInput string updated" << std::endl;
		m_text->setString(m_placeholder);
	}
}


void TextInput::set_position(const sf::Vector2f& position) {
	m_text->setPosition(position);
}

sf::Text* TextInput::get_text_object() {
	return m_text;
}