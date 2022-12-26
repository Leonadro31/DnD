#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>


class TextInput
{
private:
	sf::Text* m_text;
	sf::RectangleShape* m_background;
	sf::Vector2f m_position, m_size;
	std::string m_placeholder;

public:

	bool is_selected = false;
	
	TextInput(sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder);
	TextInput(sf::Font& font, const sf::Color& color, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder);
	~TextInput();
	

	void draw(sf::RenderWindow* window);
	void get_input(char character);
	bool check_click(const sf::Vector2i& mouse_pos);
	void set_position(const sf::Vector2f& position);
	sf::Text* get_text_object();
	

};

