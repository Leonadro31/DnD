#include "EntityStatsEditor.h"


EntityStatsEditor::EntityStatsEditor(const sf::Vector2f& position) {
	m_position = position;
}


EntityStatsEditor::~EntityStatsEditor() {
	delete m_selected_entity;
}


void EntityStatsEditor::m_link_entity_stats() {
	m_check_boxes = {
		{"vantaggio", new RoundCheckBox(sf::Vector2f(50, 220), 10, &m_selected_entity->stats->vantaggio)},
		{"svantaggio", new RoundCheckBox(sf::Vector2f(50, 250), 10, &m_selected_entity->stats->svantaggio)},
		{"blinded", new RoundCheckBox(sf::Vector2f(50, 280), 10, &m_selected_entity->stats->blinded)},
		{"charmed", new RoundCheckBox(sf::Vector2f(50, 310), 10, &m_selected_entity->stats->charmed)},
		{"deafned", new RoundCheckBox(sf::Vector2f(50, 340), 10, &m_selected_entity->stats->deafned)},
		{"frightened", new RoundCheckBox(sf::Vector2f(50, 370), 10, &m_selected_entity->stats->frightened)},
		{"grappled", new RoundCheckBox(sf::Vector2f(50, 400), 10, &m_selected_entity->stats->grappled)},
		{"incapacitated", new RoundCheckBox(sf::Vector2f(50, 430), 10, &m_selected_entity->stats->incapacitated)},
		{"invisible", new RoundCheckBox(sf::Vector2f(50, 460), 10, &m_selected_entity->stats->invisible)},
		{"paralized", new RoundCheckBox(sf::Vector2f(50, 490), 10, &m_selected_entity->stats->paralized)},
		{"petrified", new RoundCheckBox(sf::Vector2f(50, 520), 10, &m_selected_entity->stats->petrified)},
		{"poisoned", new RoundCheckBox(sf::Vector2f(50, 550), 10, &m_selected_entity->stats->poisoned)},
		{"prone", new RoundCheckBox(sf::Vector2f(50, 580), 10, &m_selected_entity->stats->prone)},
		{"restrained", new RoundCheckBox(sf::Vector2f(50, 610), 10, &m_selected_entity->stats->restrained)},
		{"stunned", new RoundCheckBox(sf::Vector2f(50, 640), 10, &m_selected_entity->stats->stunned)},
		{"unconscious", new RoundCheckBox(sf::Vector2f(50, 670), 10, &m_selected_entity->stats->unconscious)}

	};
}


void EntityStatsEditor::m_call_on_load() {
	m_check_boxes = {
		{"vantaggio", new RoundCheckBox(sf::Vector2f(50, 220), 10, &m_selected_entity->stats->vantaggio)},
		{"svantaggio", new RoundCheckBox(sf::Vector2f(50, 250), 10, &m_selected_entity->stats->svantaggio)},
		{"blinded", new RoundCheckBox(sf::Vector2f(50, 280), 10, &m_selected_entity->stats->blinded)},
		{"charmed", new RoundCheckBox(sf::Vector2f(50, 310), 10, &m_selected_entity->stats->charmed)},
		{"deafned", new RoundCheckBox(sf::Vector2f(50, 340), 10, &m_selected_entity->stats->deafned)},
		{"frightened", new RoundCheckBox(sf::Vector2f(50, 370), 10, &m_selected_entity->stats->frightened)},
		{"grappled", new RoundCheckBox(sf::Vector2f(50, 400), 10, &m_selected_entity->stats->grappled)},
		{"incapacitated", new RoundCheckBox(sf::Vector2f(50, 430), 10, &m_selected_entity->stats->incapacitated)},
		{"invisible", new RoundCheckBox(sf::Vector2f(50, 460), 10, &m_selected_entity->stats->invisible)},
		{"paralized", new RoundCheckBox(sf::Vector2f(50, 490), 10, &m_selected_entity->stats->paralized)},
		{"petrified", new RoundCheckBox(sf::Vector2f(50, 520), 10, &m_selected_entity->stats->petrified)},
		{"poisoned", new RoundCheckBox(sf::Vector2f(50, 550), 10, &m_selected_entity->stats->poisoned)},
		{"prone", new RoundCheckBox(sf::Vector2f(50, 580), 10, &m_selected_entity->stats->prone)},
		{"restrained", new RoundCheckBox(sf::Vector2f(50, 610), 10, &m_selected_entity->stats->restrained)},
		{"stunned", new RoundCheckBox(sf::Vector2f(50, 640), 10, &m_selected_entity->stats->stunned)},
		{"unconscious", new RoundCheckBox(sf::Vector2f(50, 670), 10, &m_selected_entity->stats->unconscious)}
	};

	m_texts = {

	};
}


void EntityStatsEditor::check_click(const sf::Vector2i& mouse_pos) {

	for (const auto& entry : m_check_boxes) {
		entry.second->check_click(mouse_pos);

	}
}

void EntityStatsEditor::draw(sf::RenderWindow* window) {
	if (this->first_load) {
		this->first_load = false;
		m_call_on_load();
	}

	
	for (const auto& entry : m_check_boxes) {
		entry.second->draw(window);

	}

	for (const auto& entry : m_texts) {
		entry.second->draw(window);
	}

}