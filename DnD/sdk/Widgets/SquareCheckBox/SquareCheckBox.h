#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN64
#include <Windows.h>
#endif


class SquareCheckBox
{
private:
	sf::RectangleShape* m_square = nullptr;
	sf::RectangleShape* m_inner_square = nullptr;

	sf::Vector2f m_position;
	sf::Color m_background_color;
	sf::Color m_outline_color;
	float m_outline_thickness;
	float m_side;

	sf::Vector2f m_inner_square_position;
	sf::Color m_inner_square_color;
	float m_inner_square_side;

	bool* m_buffer;

	void m_center_inner_square();

public:
	SquareCheckBox(const sf::Vector2f& position, float side, bool* buffer);
	~SquareCheckBox();

	void set_position(const sf::Vector2f position);
	void set_background_color(const sf::Color& color);
	void set_outline_color(const sf::Color& color);
	void set_checked_color(const sf::Color& color);
	void set_outline_thickness(float thickness);
	void check_click(const sf::Vector2i& mouse_pos);
	void draw(sf::RenderWindow* window);
	inline sf::RectangleShape* get_square_object() { return m_square; }
};

