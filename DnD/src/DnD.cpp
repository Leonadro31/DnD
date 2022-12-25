#include "DnD.h"


DnD::DnD(int width, int height, const char* title) {
	m_window = new RenderWindow(VideoMode(width, height), title);
	m_width = width;
	m_height = height;
	m_window->setFramerateLimit(60);
}

DnD::DnD(int width, int height, int fps, const char* title) {
	m_window = new RenderWindow(VideoMode(width, height), title);
	m_width = width;
	m_height = height;
	m_window->setFramerateLimit(fps);
}

DnD::~DnD() {
	//Clean up
}

void DnD::events_handler() {
	Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_window->close();
			this->is_running = false;
		}
	}
}


void DnD::main() {
	while (this->is_running) {
		events_handler();

		m_window->clear(Color(59, 156, 150));

		//DRAW

		m_window->display();
	}

}