#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifdef _WIN64
#include <Windows.h>
#endif

#include "../../Globals.h"

#include "../../../sdk/Widgets/include.h"

#include "../../../sdk/entities/Entity/Stats.h"
#include "../../../sdk/entities/Entity/Entity.h"


class EntityStatsEditor
{
private:
	sf::Vector2f m_position;
	Entity* m_selected_entity = new Entity(globals::get_assets_path("werewolf.png"), sf::Vector2f(695.f, 380.f), sf::Vector2f(100, 100), new Stats()); //fake ent

	std::map<std::string, RoundCheckBox*> m_check_boxes;
	std::map<std::string, TextBox*> m_texts;

	void m_call_on_load();
	void m_link_entity_stats();

public:
	EntityStatsEditor(const sf::Vector2f& position);
	~EntityStatsEditor();

	bool first_load = true;

	inline void set_selected_entity(Entity* entity) { m_selected_entity = entity; m_link_entity_stats(); }
	void check_click(const sf::Vector2i& mouse_pos);
	void draw(sf::RenderWindow* window);
};

