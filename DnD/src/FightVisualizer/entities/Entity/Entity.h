#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "../GenericEntity.h"


class Entity : public GenericEntity
{
private:
	int m_health = 0;

public:
	Entity(const std::string& texture_path, const sf::Vector2f& position, const sf::Vector2f& size, int health_points);
	~Entity();

	void draw(sf::RenderWindow* window) override;
	void check_click(const sf::Vector2i& mouse_pos) override;
	void take_damage(int damage) { m_health -= damage; }
	void set_health(int health) { m_health = health; }
};

