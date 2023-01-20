#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "../GenericEntity.h"
#include "../../../src/Globals.h"

#include "Stats.h"

class Entity : public GenericEntity
{
private:
	int m_health = 0;

public:
	Entity(const std::string& texture_path, const sf::Vector2f& position, const sf::Vector2f& size, Stats* stats);
	Entity(const std::string& texture_path, const sf::Vector2f& position, const sf::Vector2f& size);
	Entity(const std::string& texture_path, const sf::Vector2f& position, const sf::Vector2f& size, int hp);
	~Entity();

	Stats* stats;

	void draw(sf::RenderWindow* window) override;
	void check_click(const sf::Vector2i& mouse_pos) override;
	void take_damage(int damage) { m_health -= damage; }
	void set_health(int health) { m_health = health; }
};

