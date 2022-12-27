#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#ifdef _WIN64
#include <Windows.h>
#endif
#include "../sdk/Widgets/include.h"

using namespace sf;

class DnD
{
private:
	RenderWindow* m_window;
	Font* m_arial;
	int m_width, m_height;

	std::vector<TextInput*> m_input_boxes;
	std::vector<Button*> m_buttons;
	std::vector<RoundCheckBox*> m_round_check_boxes;
	std::vector<SquareCheckBox*> m_square_check_boxes;

	sf::Sprite* m_background;
	sf::Texture* m_background_texture;

	void m_load_widgets();
	void m_load_background();	

public:
	
	bool is_running = true;

	DnD(int width, int height, const char* title);
	DnD(int width, int height, int fps, const char* title);
	~DnD();

	void events_handler();
	void main();
};

