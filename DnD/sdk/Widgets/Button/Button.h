#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN64
#include <Windows.h>
#endif


class Button {
private:
	sf::RectangleShape m_rectangle;
	sf::RectangleShape m_outline;
	sf::Texture m_texture;
	sf::Text m_text;
	sf::Sprite m_sprite; // to finish
	
	sf::Vector2f m_position, m_size;
	std::string m_placeholder;

	sf::Color m_background_color;
	sf::Color m_border_color;
	sf::Color m_clicked_border_color;
	sf::Color m_clicked_background_color;
	float m_border_thickness = 3.f;
	int m_animation_count = 0;

	bool m_has_sprite = false;

	void (*m_callback)();

	void m_center_text_in_rect();


public:
	Button(sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder, void (*callback)());
	Button(std::string texture_path, sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder, void (*callback)());
	~Button();

	
	void set_background_color(const sf::Color& color);
	void set_border_color(const sf::Color& color);
	void set_clicked_border_color(const sf::Color& color);
	void set_clicked_background_color(const sf::Color& color);
	void set_border_thickness(float thickness);
	void set_font_size(int size);
	bool check_click(const sf::Vector2i& mouse_pos);
	void draw(sf::RenderWindow* window);
	inline sf::RectangleShape* get_rectangle_object() { return &m_rectangle; }
	inline sf::Sprite* get_sprite_object() { return &m_sprite; }
};