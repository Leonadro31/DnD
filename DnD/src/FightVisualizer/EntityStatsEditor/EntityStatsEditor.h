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
	Entity* m_fake_entity = new Entity(globals::get_assets_path("werewolf.png"), sf::Vector2f(695.f, 380.f), sf::Vector2f(100, 100), new Stats());
	Entity* m_selected_entity = m_fake_entity; //fake ent

	std::map<std::string, RoundCheckBox*> m_check_boxes;
	std::map<std::string, TextInput*> m_input_boxes;
	std::map<std::string, TextBox*> m_texts;

	sf::Text m_hp_text, m_ac_text, m_exhaustion_text, m_speed_text;

	TextBox* m_entity_name_box = nullptr;

	void m_call_on_load();
	void m_link_entity_stats();

public:
	EntityStatsEditor(const sf::Vector2f& position);
	~EntityStatsEditor();

	bool first_load = true;

	inline void set_selected_entity(Entity* entity) { m_selected_entity = entity; m_link_entity_stats(); }
	void check_click(const sf::Vector2i& mouse_pos);
	void check_keyboard(const sf::Event& event);
	void draw(sf::RenderWindow* window);
};

