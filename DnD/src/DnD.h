#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#ifdef _WIN64
#include <Windows.h>
#endif
#include "../sdk/TextInput/TextInput.h"
#include "../sdk/Button/Button.h"

using namespace sf;

class DnD
{
private:
	RenderWindow* m_window;
	int m_width, m_height;

	std::vector<TextInput*> input_boxes;
	Button* button;

public:
	
	bool is_running = true;

	DnD(int width, int height, const char* title);
	DnD(int width, int height, int fps, const char* title);
	~DnD();

	void events_handler();
	void main();
};

