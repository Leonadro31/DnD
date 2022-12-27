#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN64
#include <Windows.h>
#endif

class TextInput
{
private:
	sf::Text* m_text;
	sf::RectangleShape* m_background;
	sf::RectangleShape* m_line;
	sf::Vector2f m_position, m_size;
	std::string m_placeholder;
	sf::Color m_background_fill_color, m_background_border_color;
	float m_background_border_thickness = 3.f;

	int line_animation_count = 0;

	void m_center_text_in_rect();

public:
	bool is_selected = false;
	
	TextInput(sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder);
	TextInput(sf::Font& font, const sf::Color& color, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder);
	~TextInput();
	
	void draw(sf::RenderWindow* window);
	void get_input(char character);
	void get_input(bool backspace);
	void get_input(int number);
	bool check_click(const sf::Vector2i& mouse_pos);
	void set_position(const sf::Vector2f& position);
	void set_background_fill_color(const sf::Color& color);
	void set_background_border_color(const sf::Color& color);
	void set_background_border_thickness(float thickness);

	sf::Text* get_text_object();
	sf::RectangleShape* get_background_object();
};

