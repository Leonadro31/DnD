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
	
	m_input_boxes = {
		{"hp", new TextInput(*globals::fonts.at("BreatheFire"), sf::Vector2f(142, 105), sf::Vector2f(40, 20), std::to_string(m_selected_entity->stats->m_hp))},
		{"ac", new TextInput(*globals::fonts.at("BreatheFire"), sf::Vector2f(209, 126), sf::Vector2f(40, 20), std::to_string(m_selected_entity->stats->armorclass))},
		{"exhaustion", new TextInput(*globals::fonts.at("BreatheFire"), sf::Vector2f(185, 145), sf::Vector2f(40, 20), std::to_string(m_selected_entity->stats->exhaustion))},
		{"speed", new TextInput(*globals::fonts.at("BreatheFire"), sf::Vector2f(132, 165), sf::Vector2f(40, 20), std::to_string(m_selected_entity->stats->speed))}
	};

	for (const auto& entry : m_input_boxes) {
		entry.second->set_background_border_thickness(0);
		entry.second->set_background_fill_color(sf::Color(0, 0, 0, 0));
		entry.second->set_font_size(22);
	}

	for (const auto& entry : m_check_boxes) {
		entry.second->set_checked_color(sf::Color(11, 88, 135, 255));
	}

	m_entity_name_box->m_update_text(m_selected_entity->stats->Nome);
}


void EntityStatsEditor::m_call_on_load() {
	m_entity_name_box = new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(17, 18), sf::Vector2f(261, 55), m_selected_entity->stats->Nome);
	m_entity_name_box->set_background_fill_color(sf::Color(0, 0, 0, 0));
	m_entity_name_box->set_background_border_thickness(0);
	m_entity_name_box->set_font_size(30);

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
		{"vantaggio", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 210), sf::Vector2f(100, 40), "Vantaggio")},
		{"svantaggio", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 240), sf::Vector2f(100, 40), "Svantaggio")},
		{"blinded", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 270), sf::Vector2f(100, 40), "Accecato")},
		{"charmed", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 300), sf::Vector2f(100, 40), "Ammaliato")},
		{"deafned", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 330), sf::Vector2f(100, 40), "Assordato")},
		{"frightened", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 360), sf::Vector2f(100, 40), "Spaventato")},
		{"grappled", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 390), sf::Vector2f(100, 40), "Agganciato")},
		{"incapacitated", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 420), sf::Vector2f(100, 40), "Incapacitato")},
		{"invisible", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 450), sf::Vector2f(100, 40), "Invisibile")},
		{"paralized", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 480), sf::Vector2f(100, 40), "Paralizzato")},
		{"petrified", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 510), sf::Vector2f(100, 40), "Petrificato")},
		{"poisoned", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 540), sf::Vector2f(100, 40), "Avvelenato")},
		{"prone", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 570), sf::Vector2f(100, 40), "Prone")},
		{"restrained", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 600), sf::Vector2f(100, 40), "Trattenuto")},
		{"stunned", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 630), sf::Vector2f(100, 40), "Stordito")},
		{"unconscious", new TextBox(*globals::fonts.at("BreatheFire"), sf::Vector2f(85, 660), sf::Vector2f(100, 40), "Svenuto")}
	};

	m_input_boxes = {
		{"hp", new TextInput(*globals::fonts.at("BreatheFire"), sf::Vector2f(142, 105), sf::Vector2f(40, 20), "0")},
		{"ac", new TextInput(*globals::fonts.at("BreatheFire"), sf::Vector2f(209, 126), sf::Vector2f(40, 20), "0")},
		{"exhaustion", new TextInput(*globals::fonts.at("BreatheFire"), sf::Vector2f(185, 145), sf::Vector2f(40, 20), "0")},
		{"speed", new TextInput(*globals::fonts.at("BreatheFire"), sf::Vector2f(132, 165), sf::Vector2f(40, 20), "0")}
	};


	for (const auto& entry : m_check_boxes) {
		entry.second->set_checked_color(sf::Color(11, 88, 135, 255));
	}

	for (const auto& entry : m_input_boxes) {
		entry.second->set_background_border_thickness(0);
		entry.second->set_background_fill_color(sf::Color(0, 0, 0, 0));
		entry.second->set_font_size(22);
	}

	for (const auto& entry : m_texts) {
		entry.second->set_background_fill_color(sf::Color(0, 0, 0, 0));
		entry.second->set_background_border_thickness(0);
		entry.second->set_font_size(22);
	}

	m_hp_text.setFont(*globals::fonts.at("BreatheFire"));
	m_hp_text.setString("Punti Vita: ");
	m_hp_text.setColor(sf::Color::Black);
	m_hp_text.setCharacterSize(22);
	m_hp_text.setPosition(50, 100);

	m_ac_text.setFont(*globals::fonts.at("BreatheFire"));
	m_ac_text.setString("Classe Armatura: ");
	m_ac_text.setColor(sf::Color::Black);
	m_ac_text.setCharacterSize(22);
	m_ac_text.setPosition(50, 120);

	m_exhaustion_text.setFont(*globals::fonts.at("BreatheFire"));
	m_exhaustion_text.setString("Affaticamento: ");
	m_exhaustion_text.setColor(sf::Color::Black);
	m_exhaustion_text.setCharacterSize(22);
	m_exhaustion_text.setPosition(50, 140);

	m_speed_text.setFont(*globals::fonts.at("BreatheFire"));
	m_speed_text.setString("Velocita: ");
	m_speed_text.setColor(sf::Color::Black);
	m_speed_text.setCharacterSize(22);
	m_speed_text.setPosition(50, 160);
}


void EntityStatsEditor::check_click(const sf::Vector2i& mouse_pos) {

	for (const auto& entry : m_check_boxes) entry.second->check_click(mouse_pos);
	for (const auto& entry : m_input_boxes) entry.second->check_click(mouse_pos);
	

}

void EntityStatsEditor::check_keyboard(const sf::Event& event) {
	if (event.type == sf::Event::KeyReleased) {
		if (26 <= event.text.unicode && event.text.unicode <= 35) {
			int pressed_number = event.text.unicode - 26;
			
			if (m_input_boxes.at("hp")->is_selected) {
				m_input_boxes.at("hp")->get_input(pressed_number);
				try {
					m_selected_entity->stats->m_hp = std::stoi(m_input_boxes.at("hp")->get_text());
				}
				catch (...) { m_selected_entity->stats->m_hp = 0; }
				
			}
			else if (m_input_boxes.at("ac")->is_selected) {
				m_input_boxes.at("ac")->get_input(pressed_number);
				try {
					m_selected_entity->stats->armorclass = std::stoi(m_input_boxes.at("ac")->get_text());
				}
				catch (...) { m_selected_entity->stats->armorclass = 0; }
			}
			else if (m_input_boxes.at("exhaustion")->is_selected) {
				m_input_boxes.at("exhaustion")->get_input(pressed_number);
				try {
					m_selected_entity->stats->exhaustion = std::stoi(m_input_boxes.at("exhaustion")->get_text());
				}
				catch (...) { m_selected_entity->stats->exhaustion = 0; }
			}
			else if (m_input_boxes.at("speed")->is_selected) {
				m_input_boxes.at("speed")->get_input(pressed_number);
				try {
					m_selected_entity->stats->speed = std::stoi(m_input_boxes.at("speed")->get_text());
				}
				catch (...) { m_selected_entity->stats->speed = 0; }
			}

		}
		else if (event.text.unicode == 59) {
			for (const auto& entry : m_input_boxes) {
				entry.second->get_input(true);
			}
		}
	}
}

void EntityStatsEditor::draw(sf::RenderWindow* window) {
	if (this->first_load) {
		this->first_load = false;
		m_call_on_load();
	}

	m_entity_name_box->draw(window);
	
	window->draw(m_hp_text);
	window->draw(m_ac_text);
	window->draw(m_speed_text);
	window->draw(m_exhaustion_text);

	for (const auto& entry : m_check_boxes) entry.second->draw(window);
	for (const auto& entry : m_input_boxes) entry.second->draw(window);
	for (const auto& entry : m_texts) entry.second->draw(window);

}