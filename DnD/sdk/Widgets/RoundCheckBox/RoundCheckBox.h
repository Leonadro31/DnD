#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN64
#include <Windows.h>
#endif


class RoundCheckBox
{
private:
	sf::CircleShape* m_circle = nullptr;
	sf::CircleShape* m_inner_circle = nullptr;

	sf::Vector2f m_position;
	sf::Color m_background_color;
	sf::Color m_outline_color;
	float m_outline_thickness;
	float m_radius;

	sf::Vector2f m_inner_circle_position;
	sf::Color m_inner_circle_color;
	float m_inner_circle_radius;
	
	bool* m_buffer;

	void m_center_inner_circle();

public:
	RoundCheckBox(const sf::Vector2f& position, float radius, bool* buffer);
	~RoundCheckBox();
	
	void set_position(const sf::Vector2f position);
	void set_background_color(const sf::Color& color);
	void set_outline_color(const sf::Color& color);
	void set_checked_color(const sf::Color& color);
	void set_outline_thickness(float thickness);
	void check_click(const sf::Vector2i& mouse_pos);
	void draw(sf::RenderWindow* window);
	sf::CircleShape* get_circle_object();
};

