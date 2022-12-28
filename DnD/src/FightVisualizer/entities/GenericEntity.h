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
private:
	sf::Vector2f m_position;
	sf::Vector2f m_size;

	sf::Sprite* m_sprite = nullptr;
	sf::Texture* m_texture = nullptr;

	

public:
	GenericEntity(const std::string& texture_path,const sf::Vector2f& position, const sf::Vector2f& size);

	~GenericEntity();

	void set_position(const sf::Vector2f& position);
	void set_size(const sf::Vector2f& size);
	void set_texture(const std::string& texture_path);
	void draw(sf::RenderTexture* window);
};

