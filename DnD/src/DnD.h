#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace sf;

class DnD
{
private:
	RenderWindow* m_window;
	int m_width, m_height;

public:
	
	bool is_running = true;

	DnD(int width, int height, const char* title);
	DnD(int width, int height, int fps, const char* title);
	~DnD();

	void events_handler();
	void main();
};

