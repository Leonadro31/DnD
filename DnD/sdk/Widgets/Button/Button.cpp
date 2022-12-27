#include "Button.h"


Button::Button(sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder, void (*callback)()) {
	m_rectangle = new sf::RectangleShape();
	m_outline = new sf::RectangleShape();
	m_text = new sf::Text();

	m_placeholder = placeholder;
	m_position = position;
	m_size = size;
	m_callback = callback;

	m_background_color = sf::Color(71, 121, 143, 255);
	m_clicked_background_color = sf::Color(71, 121, 143, 255);
	m_clicked_border_color = sf::Color();

	m_rectangle->setPosition(m_position);
	m_rectangle->setSize(m_size);
	m_rectangle->setFillColor(sf::Color(71, 121, 143, 255));

	m_outline->setPosition(m_position);
	m_outline->setSize(m_size);
	m_outline->setFillColor(sf::Color(0, 0, 0, 0));
	m_outline->setOutlineColor(sf::Color::Black);
	m_outline->setOutlineThickness(3);

	m_text->setString(placeholder);
	m_text->setFillColor(sf::Color::Black);
	m_text->setFont(font);

	m_center_text_in_rect();

	std::cout << "[Debug] Created Button." << std::endl;
}

Button::Button(std::string texture_path, sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder, void (*callback)()) {
	m_text = new sf::Text();
	m_sprite = new sf::Sprite();
	m_texture = new sf::Texture();

	m_placeholder = placeholder;
	m_position = position;
	m_size = size;
	m_callback = callback;
	
	if (!m_texture->loadFromFile(texture_path)) std::cout << "[-] Couldn't load file: " << texture_path << std::endl;

	m_sprite->setTexture(*m_texture);
	sf::FloatRect sprite_size = m_sprite->getGlobalBounds();
	m_sprite->setScale(sf::Vector2f(size.x / sprite_size.width, size.y / sprite_size.height));
	m_sprite->setPosition(m_position);

	m_text->setString(placeholder);
	m_text->setFillColor(sf::Color(0, 0, 0, 220));
	m_text->setFont(font);

	std::cout << "[Debug] Created Button with texture (" << texture_path << ")." << std::endl;
}


Button::~Button() {
	delete m_rectangle;
	delete m_text;
	delete m_outline;
	delete m_sprite;
	std::cout << "[Debug] Deleted Button." << std::endl;
}

void Button::m_center_text_in_rect() {
	sf::FloatRect text_rect = m_text->getLocalBounds();
	m_text->setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
	m_text->setPosition(sf::Vector2f(m_position.x + m_size.x / 2, m_position.y + m_size.y / 2));
}


void Button::set_background_color(const sf::Color& color) {
	if (m_sprite != nullptr) return;
	m_background_color = color;
	m_rectangle->setFillColor(m_background_color);
}


void Button::set_border_color(const sf::Color& color) {
	if (m_sprite != nullptr) return;
	m_border_color = color;
	m_outline->setOutlineColor(color);
}


void Button::set_clicked_border_color(const sf::Color& color) {
	if (m_sprite != nullptr) return;
	m_clicked_border_color = color;
}


void Button::set_clicked_background_color(const sf::Color& color) {
	if (m_sprite != nullptr) return;
	m_clicked_background_color = color;
}

void Button::set_border_thickness(float thickness) {
	if (m_sprite != nullptr) return;
	m_border_thickness = thickness;
	m_outline->setOutlineThickness(thickness);
}


void Button::set_font_size(int size) {
	m_text->setCharacterSize(size);
	m_center_text_in_rect();
}

void Button::draw(sf::RenderWindow* window) {
	if (m_sprite != nullptr) {
		window->draw(*m_sprite);
		window->draw(*m_text);
	}
	else {
		m_animation_count--;
		if (m_animation_count > 0) {
			m_outline->setOutlineColor(m_clicked_border_color);
			m_rectangle->setFillColor(m_clicked_background_color);
		}
		else {
			m_outline->setOutlineColor(m_border_color);
			m_rectangle->setFillColor(m_background_color);
		}
		window->draw(*m_rectangle);
		window->draw(*m_text);
		window->draw(*m_outline);
	}
	
}

void Button::check_click(const sf::Vector2i& mouse_pos) {
	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_size.x) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_size.y)) {
		std::cout << "[Debug] Button clicked." << std::endl;
		m_animation_count = 15;
		m_callback();
	}
}


sf::Sprite* Button::get_sprite_object() {
	return m_sprite;
}


sf::RectangleShape* Button::get_rectangle_object() {
	return m_rectangle;
}