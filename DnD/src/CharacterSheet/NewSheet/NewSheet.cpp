#include "NewSheet.h"

TextBox::TextBox(sf::Font& font, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder) {
	m_text = new sf::Text();
	m_background = new sf::RectangleShape();
	m_line = new sf::RectangleShape();

	m_text->setFont(font);
	m_text->setFillColor(sf::Color::Black);
	m_text->setString(placeholder);

	m_background->setPosition(position);
	m_background->setSize(size);
	m_background->setFillColor(sf::Color(71, 121, 143, 255));
	m_background->setOutlineColor(sf::Color(68, 104, 120, 255));
	m_background->setOutlineThickness(3);

	m_line->setPosition(sf::Vector2f(position.x, position.y + size.y));
	m_line->setSize(sf::Vector2f(size.x, m_background_border_thickness));
	m_line->setFillColor(sf::Color::Black);

	m_position = position;
	m_size = size;
	m_placeholder = placeholder;
	m_background_border_color = sf::Color(68, 104, 120, 255);
	m_background_fill_color = sf::Color(71, 121, 143, 255);
	m_background_border_thickness = 3.f;

	m_center_text_in_rect();

	std::cout << "[Debug] Created TextInput" << std::endl;
}

TextBox::TextBox(sf::Font& font, const sf::Color& color, const sf::Vector2f& position, const sf::Vector2f& size, const std::string& placeholder) {
	m_text = new sf::Text();
	m_background = new sf::RectangleShape();
	m_line = new sf::RectangleShape();

	m_text->setFont(font);
	m_text->setFillColor(color);
	m_text->setString(placeholder);

	m_background->setPosition(position);
	m_background->setSize(size);
	m_background->setFillColor(sf::Color::White);
	m_background->setOutlineColor(sf::Color::Black);
	m_background->setOutlineThickness(5);

	m_line->setPosition(sf::Vector2f(position.x, position.y + size.y));
	m_line->setSize(sf::Vector2f(size.x, m_background_border_thickness));
	m_line->setFillColor(sf::Color::Black);

	m_position = position;
	m_size = size;
	m_placeholder = placeholder;
	m_background_border_color = sf::Color(68, 104, 120, 255);
	m_background_fill_color = sf::Color(71, 121, 143, 255);
	m_background_border_thickness = 3.f;

	m_center_text_in_rect();

	std::cout << "[Debug] Created TextInput" << std::endl;

}

TextBox::~TextBox() {
	std::cout << "[Debug] Deleting TextInput" << std::endl;
	delete m_text;
	delete m_background;
	delete m_line;
}


void TextBox::m_center_text_in_rect() {
	sf::FloatRect text_rect = m_text->getLocalBounds();
	m_text->setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
	m_text->setPosition(sf::Vector2f(m_position.x + m_size.x / 2, m_position.y + m_size.y / 2));
}


void TextBox::draw(sf::RenderWindow* win) {
	win->draw(*m_background);
	win->draw(*m_text);

	if (is_selected) {
		line_animation_count++;
		if (line_animation_count < 180) m_line->setFillColor(sf::Color::Black);
		else if (line_animation_count < 360) m_line->setFillColor(m_background_border_color);
		else line_animation_count = 0;
		win->draw(*m_line);
	}

}


bool TextBox::check_click(const sf::Vector2i& mouse_pos) {
	if ((mouse_pos.x >= m_position.x && mouse_pos.x <= m_position.x + m_size.x) && (mouse_pos.y >= m_position.y && mouse_pos.y <= m_position.y + m_size.y)) {
		is_selected = true;
		std::cout << "[Debug] TextInput Selected" << std::endl;
		return true;
	}
	is_selected = false;
	return false;
}


void TextBox::get_input(char character) {
	if (!is_selected) return;

	m_placeholder.push_back(character);
	m_text->setString(m_placeholder);
	if (m_text->getLocalBounds().width > m_size.x) {
		m_placeholder.pop_back();
		m_text->setString(m_placeholder);
	}
	else {
		m_text->setString(m_placeholder);
		m_center_text_in_rect();
	}
}

void TextBox::get_input(int number) {
	if (!is_selected) return;

	m_placeholder += std::to_string(number);
	m_text->setString(m_placeholder);
	if (m_text->getLocalBounds().width > m_size.x) {
		m_placeholder.pop_back();
		m_text->setString(m_placeholder);
	}
	else {
		m_text->setString(m_placeholder);
		m_center_text_in_rect();
	}
}


void TextBox::get_input(bool backspace) {
	if (!is_selected) return;
	if (m_placeholder.length() <= 0) return;

	m_placeholder.pop_back();
	m_text->setString(m_placeholder);
	m_text->setString(m_placeholder);
	m_center_text_in_rect();
}


void TextBox::set_position(const sf::Vector2f& position) {
	m_position = position;
	m_text->setPosition(m_position);
}

void TextBox::set_font_size(int size) {
	m_text->setCharacterSize(size);
	m_center_text_in_rect();
}

void TextBox::set_background_fill_color(const sf::Color& color) {
	m_background_fill_color = color;
	m_background->setFillColor(m_background_fill_color);
}


void TextBox::set_background_border_color(const sf::Color& color) {
	m_background_border_color = color;
	m_background->setOutlineColor(m_background_border_color);
}


void TextBox::set_background_border_thickness(float thickness) {
	m_background_border_thickness = thickness;
	m_background->setOutlineThickness(m_background_border_thickness);
}









NewSheet::NewSheet(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab) {
	m_fonts = fonts;
	m_is_running = is_running;
	m_current_tab = current_tab;
}

NewSheet::~NewSheet() {
	delete m_fonts;
	delete m_is_running;
	delete m_current_tab;
}

void NewSheet::m_load_widgets() {

	m_buttons.push_back(new Button(globals::get_assets_path("button.png"), *m_fonts->at("BreatheFire"), sf::Vector2f(0.f, 0.f), sf::Vector2f(40.0, 40.f), "<-", 0));
	
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(69.f, 114.f), sf::Vector2f(240.0, 40.f),"")); //nome pg
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(518.f, 95.f), sf::Vector2f(210.0, 20.f), "")); // classe e lvl
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(754.f, 95.f), sf::Vector2f(170.0, 20.f), "")); // background
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(952.f, 95.f), sf::Vector2f(170.0, 20.f), "")); //nome player
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(518.f, 150.f), sf::Vector2f(210.0, 20.f), "")); //razza
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(754.f, 150.f), sf::Vector2f(170.0, 20.f), "")); // allineamento
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(952.f, 150.f), sf::Vector2f(170.0, 20.f), "")); //exp
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(44.f, 301.f), sf::Vector2f(55.0, 55.f), "")); //Forza
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(180.f, 300.f), sf::Vector2f(55.0, 55.f), "")); //Intelligenza
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(44.f, 450.f), sf::Vector2f(55.0, 55.f), "")); //dex
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(180.f, 449.f), sf::Vector2f(55.0, 55.f), "")); //wis
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(44.f, 598.f), sf::Vector2f(55.0, 55.f), "")); //con
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(180.f, 598.f), sf::Vector2f(55.0, 55.f), "")); //cha
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(303.f, 265.f), sf::Vector2f(34.0, 34.f), "")); //Ispirazione
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(846.f, 285.f), sf::Vector2f(45.0, 45.f), "")); //CA
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(956.f, 430.f), sf::Vector2f(75.0, 55.f), "")); //vita att.
	m_text_input.push_back(new TextInput(*m_fonts->at("BreatheFire"), sf::Vector2f(956.f, 539.f), sf::Vector2f(75.0, 55.f), "")); //vita temp.

	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f,269.f),6, &m_stats.m_ability_check_acrobazia)); //acrobazia
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 297.f),6, &m_stats.m_ability_check_animali)); //addestrare animali
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 325.f), 6, &m_stats.m_ability_check_arcana));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 353.f), 6, &m_stats.m_ability_check_atletica));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 381.f), 6, &m_stats.m_ability_check_furtività));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 409.f), 6, &m_stats.m_ability_check_indagare));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 438.f), 6, &m_stats.m_ability_check_inganno));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 466.f), 6, &m_stats.m_ability_check_intimidire));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 494.f), 6, &m_stats.m_ability_check_intrattenere));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 522.f), 6, &m_stats.m_ability_check_intuizione));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 550.f), 6, &m_stats.m_ability_check_medicina));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 578.f), 6, &m_stats.m_ability_check_natura));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 606.f), 6, &m_stats.m_ability_check_percezione));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 634.f), 6, &m_stats.m_ability_check_persuasione));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 662.f), 6, &m_stats.m_ability_check_rapidità));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 690.f), 6, &m_stats.m_ability_check_religione));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 718.f), 6, &m_stats.m_ability_check_sopravvivenza));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(562.f, 746.f), 6, &m_stats.m_ability_check_storia));

	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 431.f), 6, &m_stats.m_sav_throw_str));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 459.f), 6, &m_stats.m_sav_throw_dex));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 487.f), 6, &m_stats.m_sav_throw_con));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 515.f), 6, &m_stats.m_sav_throw_int));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 543.f), 6, &m_stats.m_sav_throw_wis));
	m_round_check_box.push_back(new RoundCheckBox(sf::Vector2f(308.f, 571.f), 6, &m_stats.m_sav_throw_cha));

	for (const auto& button : m_buttons) {
		button->set_font_size(20);
	}

	for (const auto& textinput : m_text_input) {
		textinput->set_background_fill_color(sf::Color(0, 0, 0, 0));
		textinput->set_background_border_color(sf::Color(0, 0, 0, 0));
	}
}

void NewSheet::m_load_text_box() {
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(301.f, 339.f), sf::Vector2f(43.0, 43.f), ""));// bonus

	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(56.f, 369.f), sf::Vector2f(30.0, 23.f), ""));//For
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(193.f, 368.f), sf::Vector2f(30.0, 23.f), ""));//Int
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(56.f, 519.f), sf::Vector2f(30.0, 23.f), "")); //dex
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(193.f, 518.f), sf::Vector2f(30.0, 23.f), ""));//wis
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(56.f, 669.f), sf::Vector2f(30.0, 23.f), "")); //con
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(193.f, 668.f), sf::Vector2f(30.0, 23.f), "")); //cha

	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 264.f), sf::Vector2f(15.0, 15.f), "")); //acrobazia
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 292.f), sf::Vector2f(15.0, 15.f), "")); //animali
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 320.f), sf::Vector2f(15.0, 15.f), "")); //arcana
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 348.f), sf::Vector2f(15.0, 15.f), "")); //atletica
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 376.f), sf::Vector2f(15.0, 15.f), "")); //furtività
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 404.f), sf::Vector2f(15.0, 15.f), "")); //indagare
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 432.f), sf::Vector2f(15.0, 15.f), "")); //inganno
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 460.f), sf::Vector2f(15.0, 15.f), "")); //intimidire
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 488.f), sf::Vector2f(15.0, 15.f), "")); //intrattenere
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 516.f), sf::Vector2f(15.0, 15.f), "")); //intuizione
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 544.f), sf::Vector2f(15.0, 15.f), "")); //medicina
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 572.f), sf::Vector2f(15.0, 15.f), "")); //natura
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 600.f), sf::Vector2f(15.0, 15.f), "")); //percezione
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 628.f), sf::Vector2f(15.0, 15.f), "")); //persuasione
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 656.f), sf::Vector2f(15.0, 15.f), "")); //rapidità
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 684.f), sf::Vector2f(15.0, 15.f), "")); //religione
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 712.f), sf::Vector2f(15.0, 15.f), "")); //sopravvivenza
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(591.f, 740.f), sf::Vector2f(15.0, 15.f), "")); //storia

	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(340.f, 428.f), sf::Vector2f(15.0, 15.f), "")); //forza sav
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(340.f, 456.f), sf::Vector2f(15.0, 15.f), "")); // dex sav
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(340.f, 484.f), sf::Vector2f(15.0, 15.f), ""));//con sav
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(340.f, 512.f), sf::Vector2f(15.0, 15.f), ""));//int sav
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(340.f, 540.f), sf::Vector2f(15.0, 15.f), ""));//wis sav
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(340.f, 568.f), sf::Vector2f(15.0, 15.f), ""));//cha sav

	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(300.f, 662.f), sf::Vector2f(43.0, 43.f), ""));// pass. perc.
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(1020.f, 390.f), sf::Vector2f(100.0, 20.f), ""));// vita tot
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(963.f, 285.f), sf::Vector2f(45.0, 45.f), "")); //iniziat.
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(1084.f, 285.f), sf::Vector2f(45.0, 45.f), ""));//velocità
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(890.f, 646.f), sf::Vector2f(60.0, 15.f), ""));// dadi vita tot
	m_text_output.push_back(new TextBox(*m_fonts->at("BreatheFire"), sf::Vector2f(875.f, 678.f), sf::Vector2f(55.0, 40.f), ""));//dadi vita att.

	for (const auto& textoutput : m_text_output) {
		textoutput->set_background_fill_color(sf::Color(0, 0, 0, 0));
		textoutput->set_background_border_color(sf::Color(0, 0, 0, 0));
		textoutput->set_font_size(15);
	}
}

void NewSheet::call_on_load() {
	m_window = new sf::RenderWindow(sf::VideoMode(1200, 840), "DnD - Nuova Sheda", sf::Style::Titlebar | sf::Style::Close);
	m_background_texture.loadFromFile(globals::get_assets_path("CharacterSheet.png"));
	m_background.setTexture(m_background_texture);

	m_load_widgets();
	m_load_text_box();
}

void NewSheet::m_event_handler() {
	sf::Event event;
	bool is_caps = false;
	while (m_window->pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
		{
			m_window->close();
			*this->m_is_running = false;
		}

		if (event.type == sf::Event::MouseButtonReleased) {
			sf::Vector2i mouse_pos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
			std::cout << "[Debug] Click Pos: (" << mouse_pos.x << ", " << mouse_pos.y << ")" << std::endl;

			for (const auto& button : m_buttons) button->check_click(mouse_pos);

			if (m_buttons[0]->check_click(mouse_pos)) {
				*m_current_tab = "CharacterSheet";
				m_first_load = true;
				m_window->close();
			}

			for (const auto& textinput : m_text_input) textinput->check_click(mouse_pos);

			for (const auto& roundcheck : m_round_check_box) roundcheck->check_click(mouse_pos);
			
			if (m_stats.m_ability_check_acrobazia) {
				int n = m_stats.DexMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[7]->m_update_text(N);
			}
			if (m_stats.m_ability_check_animali) {
				int n = m_stats.WisMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[8]->m_update_text(N);
			}
			if (m_stats.m_ability_check_arcana) {
				int n = m_stats.IntMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[9]->m_update_text(N);
			}
			if (m_stats.m_ability_check_atletica) {
				int n = m_stats.StrMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[10]->m_update_text(N);
			}
			if (m_stats.m_ability_check_furtività) {
				int n = m_stats.DexMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[11]->m_update_text(N);
			}
			if (m_stats.m_ability_check_indagare) {
				int n = m_stats.IntMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[12]->m_update_text(N);
			}
			if (m_stats.m_ability_check_inganno) {
				int n = m_stats.ChaMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[13]->m_update_text(N);
			}
			if (m_stats.m_ability_check_intimidire) {
				int n = m_stats.ChaMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[14]->m_update_text(N);
			}
			if (m_stats.m_ability_check_intrattenere) {
				int n = m_stats.ChaMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[15]->m_update_text(N);
			}
			if (m_stats.m_ability_check_intuizione) {
				int n = m_stats.WisMod+ m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[16]->m_update_text(N);
			}
			if (m_stats.m_ability_check_medicina) {
				int n = m_stats.WisMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[17]->m_update_text(N);
			}
			if (m_stats.m_ability_check_natura) {
				int n = m_stats.IntMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[18]->m_update_text(N);
			}
			if (m_stats.m_ability_check_percezione) {
				int n = m_stats.WisMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[19]->m_update_text(N);
			}
			if (m_stats.m_ability_check_persuasione) {
				int n = m_stats.ChaMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[20]->m_update_text(N);
			}
		    if (m_stats.m_ability_check_rapidità) {
				int n = m_stats.DexMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[21]->m_update_text(N);
			}
			if (m_stats.m_ability_check_religione) {
				int n = m_stats.IntMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[22]->m_update_text(N);
			}
			if (m_stats.m_ability_check_sopravvivenza) {
				int n = m_stats.WisMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[23]->m_update_text(N);
			}
			if (m_stats.m_ability_check_storia) {
				int n = m_stats.IntMod + m_stats.m_bonus;
				std::stringstream ss;
				std::string N;
				ss << n;
				ss >> N;
				m_text_output[24]->m_update_text(N);
			}

		}

		if (event.type == sf::Event::KeyPressed) {

		}

		if (event.type == sf::Event::KeyReleased) {
			//	std::cout << "[Debug] Key: " << event.text.unicode << std::endl;

			if (event.text.unicode == 4294967295) {
				//caps lock
			}

			if (event.text.unicode <= 25) {
				char pressed_letter = static_cast<char>(event.text.unicode + 0x41);;

				if (is_caps && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);
				if (!is_caps && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);

				for (TextInput* input_box : m_text_input) {
					if (m_text_input[7]->is_selected || m_text_input[8]->is_selected || m_text_input[9]->is_selected || m_text_input[10]->is_selected || m_text_input[11]->is_selected || m_text_input[12]->is_selected) {
						std::cout << "[Debug] Key: " << event.text.unicode << std::endl;
						break;
					}
					else { 
						input_box->get_input(pressed_letter); 
					}
				}
			}
			else if (event.text.unicode == 57) {
				for (TextInput* input_box : m_text_input) {
					input_box->get_input(' ');
				}
			}
			else if (26 <= event.text.unicode && event.text.unicode <= 35) {
				int pressed_number = event.text.unicode - 26;
				for (TextInput* input_box : m_text_input) {
					input_box->get_input(pressed_number);
				}
			}
			else if (event.text.unicode == 58) {
				for (TextInput* input_box : m_text_input) {
					if (m_text_input[1]->is_selected) {
						if (m_text_input[1]->get_text() == "") {
							std::cout << "error" << std::endl;
							break;
						}
						std::string given_str = m_text_input[1]->get_text();
						std::string delim = " ";
						size_t pos;
						pos = given_str.find(delim);
						m_stats.Classe = given_str.substr(0, pos);					
						m_stats.Livello = given_str.substr(pos+1, given_str.size());
						std::cout << m_stats.Classe<< std::endl;
						std::cout << m_stats.Livello<< std::endl;
						m_stats.m_lvl = stoi(m_stats.Livello);
						if (m_stats.m_lvl >= 1 && m_stats.m_lvl <= 4) {
							m_stats.m_bonus = 2;
						}
						else if (m_stats.m_lvl >= 5 && m_stats.m_lvl <= 8) {
							m_stats.m_bonus = 3;
						}
						else if (m_stats.m_lvl >= 9 && m_stats.m_lvl <= 12) {
							m_stats.m_bonus = 4;
						}
						else if (m_stats.m_lvl >= 13 && m_stats.m_lvl <= 16) {
							m_stats.m_bonus = 5;
						}
						else if (m_stats.m_lvl >= 17 && m_stats.m_lvl <= 20) {
							m_stats.m_bonus = 6;
						}
						std::stringstream ss;
						ss << m_stats.m_bonus;
						ss >> m_stats.Bonus;
						m_text_output[0]->m_update_text(m_stats.Bonus);
						if (m_stats.Classe == "artefice") {
							m_stats.m_hitdice = 10;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.IntMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "barbaro") {
							m_stats.m_hitdice = 12;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "bardo") {
							m_stats.m_hitdice = 8;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.ChaMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "chierico") {
							m_stats.m_hitdice = 8;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.WisMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "druido") {
							m_stats.m_hitdice = 8;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.WisMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "guerriero") {
							m_stats.m_hitdice = 10;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "ladro") {
							m_stats.m_hitdice = 8;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "mago") {
							m_stats.m_hitdice = 6;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.IntMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "monaco") {
							m_stats.m_hitdice = 8;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "paladino") {
							m_stats.m_hitdice = 10;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.ChaMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "ranger") {
							m_stats.m_hitdice = 10;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.WisMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "strgone") {
							m_stats.m_hitdice = 8;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.ChaMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else if (m_stats.Classe == "warlock") {
							m_stats.m_hitdice = 10;
							m_stats.m_savedc = 8 + m_stats.m_bonus + m_stats.ChaMod;
							std::stringstream ss;
							ss << m_stats.m_hitdice;
							ss >> m_stats.DadiVita;
						}
						else {
							std::cout << "error";
						}
						std::string D = m_stats.Livello + "d" + m_stats.DadiVita;
						std::cout << "Vita: " << m_stats.m_hp;
						m_stats.m_hp = m_stats.m_hitdice + (m_stats.m_lvl - 1) * ((m_stats.m_hitdice / 2) + 1) + m_stats.m_lvl * ((m_stats.ConMod));
						std::stringstream vv;
						vv << m_stats.m_hp;
						vv >> m_stats.Vita;
						m_text_output[35]->m_update_text(D);
						m_text_output[32]->m_update_text(m_stats.Vita);
						break;
					}
					else if (m_text_input[2]->is_selected) {
						m_stats.BackGround = m_text_input[2]->get_text();
						std::cout << m_stats.BackGround << std::endl;
						break;
					}
					else if (m_text_input[4]->is_selected) {
						m_stats.Razza = m_text_input[4]->get_text();
						std::cout << m_stats.Razza << std::endl;
						break;
					}
					else if (m_text_input[7]->is_selected) {
						if (m_text_input[7]->get_text() == "") {
							std::cout << "error" << std::endl;
							break;
						}
						else {
							m_stats.Forza = m_text_input[7]->get_text();
							m_stats.Str = stoi(m_stats.Forza);
							m_stats.StrMod = (m_stats.Str / 2) - 5;
							std::stringstream ss;
							ss << m_stats.StrMod;
							ss >> m_stats.ModFor;
							m_text_output[1]->m_update_text(m_stats.ModFor);
							m_text_output[10]->m_update_text(m_stats.ModFor);
							m_text_output[25]->m_update_text(m_stats.ModFor);
							std::cout << "Str Modifier: " << m_stats.ModFor;
							break;
						}
						
					}
					else if (m_text_input[8]->is_selected) {
						if (m_text_input[8]->get_text() == "") {
							std::cout << "error" << std::endl;
							break;
						}
						else{
							m_stats.Intelligenza = m_text_input[8]->get_text();
							m_stats.Int = stoi(m_stats.Intelligenza);
							m_stats.IntMod = (m_stats.Int / 2) - 5;
							std::stringstream ss;
							ss << m_stats.IntMod;
							ss >> m_stats.ModInt;
							m_text_output[2]->m_update_text(m_stats.ModInt);
							m_text_output[9]->m_update_text(m_stats.ModInt);
							m_text_output[12]->m_update_text(m_stats.ModInt);
							m_text_output[18]->m_update_text(m_stats.ModInt);
							m_text_output[22]->m_update_text(m_stats.ModInt);
							m_text_output[24]->m_update_text(m_stats.ModInt);
							m_text_output[28]->m_update_text(m_stats.ModInt);
							std::cout << "Int Modifier: " << m_stats.ModInt;
							break;
						}
						
					}
					else if (m_text_input[9]->is_selected) {
						if (m_text_input[9]->get_text() == "") {
							std::cout << "error" << std::endl;
							break;
						}
						else {
							m_stats.Destrezza = m_text_input[9]->get_text();
							m_stats.Dex = stoi(m_stats.Destrezza);
							m_stats.DexMod = (m_stats.Dex / 2) - 5;
							std::stringstream ss;
							ss << m_stats.DexMod;
							ss >> m_stats.ModDes;
							m_text_output[3]->m_update_text(m_stats.ModDes);
							m_text_output[7]->m_update_text(m_stats.ModDes);
							m_text_output[11]->m_update_text(m_stats.ModDes);
							m_text_output[21]->m_update_text(m_stats.ModDes);
							m_text_output[26]->m_update_text(m_stats.ModDes);
							std::cout << "Dex Modifier: " << m_stats.ModDes;
							break;
						}
					}
					else if (m_text_input[10]->is_selected) {
						if (m_text_input[10]->get_text() == "") {
							std::cout << "error" << std::endl;
							break;
						}
						else{
							m_stats.Saggeza = m_text_input[10]->get_text();
							m_stats.Wis = stoi(m_stats.Saggeza);
							m_stats.WisMod = (m_stats.Wis / 2) - 5;
							std::stringstream ss;
							ss << m_stats.WisMod;
							ss >> m_stats.ModSag;
							m_text_output[4]->m_update_text(m_stats.ModSag);
							m_text_output[8]->m_update_text(m_stats.ModSag);
							m_text_output[16]->m_update_text(m_stats.ModSag);
							m_text_output[17]->m_update_text(m_stats.ModSag);
							m_text_output[19]->m_update_text(m_stats.ModSag);
							m_text_output[23]->m_update_text(m_stats.ModSag);
							m_text_output[29]->m_update_text(m_stats.ModSag);
							std::cout << "Wis Modifier: " << m_stats.ModSag;
							break;
						}
						
					}
					else if (m_text_input[11]->is_selected) {
						if (m_text_input[11]->get_text() == "") {
							std::cout << "error" << std::endl;
							break;
						}
						else{
							m_stats.Costituzione = m_text_input[11]->get_text();
							m_stats.Con = stoi(m_stats.Costituzione);
							m_stats.ConMod = (m_stats.Con / 2) - 5;
							std::stringstream ss;
							ss << m_stats.ConMod;
							ss >> m_stats.ModCos;
							m_text_output[5]->m_update_text(m_stats.ModCos);
							m_text_output[27]->m_update_text(m_stats.ModCos);
							std::cout << "Con Modifier: " << m_stats.ModCos;
							break;
						}
						
					}
					else if (m_text_input[12]->is_selected) {
						if (m_text_input[12]->get_text() == "") {
							std::cout << "error" << std::endl;
							break;
						}
						else{
							m_stats.Carisma = m_text_input[12]->get_text();
							m_stats.Cha = stoi(m_stats.Carisma);
							m_stats.ChaMod = (m_stats.Cha / 2) - 5;
							std::stringstream ss;
							ss << m_stats.ChaMod;
							ss >> m_stats.ModCar;
							m_text_output[6]->m_update_text(m_stats.ModCar);
							m_text_output[13]->m_update_text(m_stats.ModCar);
							m_text_output[14]->m_update_text(m_stats.ModCar);
							m_text_output[15]->m_update_text(m_stats.ModCar);
							m_text_output[20]->m_update_text(m_stats.ModCar);
							m_text_output[30]->m_update_text(m_stats.ModCar);
							std::cout << "Cha Modifier: " << m_stats.ModCar;
							break;
						}	
					}
					else {
						std::cout << "[Debug] Key: " << event.text.unicode << std::endl;
						break;
					}
				}
			}
			else if (event.text.unicode == 59) {
				for (TextInput* input_box : m_text_input) {
					input_box->get_input(true);
				}
			}
			else {
				std::cout << "[Debug] Key: " << event.text.unicode << std::endl;
			}




		}
	}
}


void NewSheet::main() {
	if (m_first_load) {
		call_on_load();
		m_first_load = false;
	}

	m_event_handler();

	m_window->clear(sf::Color::Black);
	m_window->draw(m_background);
	
	for (const auto& button : m_buttons) button->draw(m_window);
	for (const auto& textinput: m_text_input) textinput->draw(m_window);
	for (const auto& roundcheck : m_round_check_box) roundcheck->draw(m_window);
	for (const auto& textoutput : m_text_output) textoutput->draw(m_window);


	m_window->display();


}
