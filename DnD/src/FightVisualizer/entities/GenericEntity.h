#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN64
#include <Windows.h>
#endif


class GenericEntity
{
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_size;

	sf::CircleShape m_marker;

	sf::Sprite* m_sprite = nullptr;
	sf::Texture* m_texture = nullptr;

	bool m_is_selected = false;

	void m_center_marker();

public:
	GenericEntity(const std::string& texture_path,const sf::Vector2f& position, const sf::Vector2f& size);

	~GenericEntity();

	virtual void set_position(const sf::Vector2f& position);
	virtual void set_size(const sf::Vector2f& size);
	virtual void set_texture(const std::string& texture_path);
	virtual void draw(sf::RenderWindow* window);
	virtual bool is_selected() { return m_is_selected; }
	virtual void check_click(const sf::Vector2i& mouse_pos);

};

