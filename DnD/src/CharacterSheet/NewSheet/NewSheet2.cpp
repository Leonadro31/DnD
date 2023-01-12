#include "NewSheet2.h"

NewSheet2::NewSheet2(std::map<std::string, sf::Font*>* fonts, bool* is_running, std::string* current_tab, Stats* stats) {
	m_fonts = fonts;
	m_is_running = is_running;
	m_current_tab = current_tab;
	m_stats = stats;
}

NewSheet2::~NewSheet2() {
	delete m_fonts;
	delete m_is_running;
	delete m_current_tab;
}


void NewSheet2::m_load_widgets(){
	m_buttons.push_back(new Button(globals::get_assets_path("button.png"), *m_fonts->at("BreatheFire"), sf::Vector2f(0.f, 0.f), sf::Vector2f(40.0, 40.f), "<-", 0));
	m_buttons.push_back(new Button(globals::get_assets_path("button.png"), *m_fonts->at("BreatheFire"), sf::Vector2f(1140.f, 0.f), sf::Vector2f(60.0, 40.f), "", 0));
}

void NewSheet2::m_load_text_box(){
}

void NewSheet2::call_on_load() {
	m_window = new sf::RenderWindow(sf::VideoMode(1200, 840), "DnD - Nuova Sheda", sf::Style::Titlebar | sf::Style::Close);
	m_background_texture.loadFromFile(globals::get_assets_path("CharacterSheet2.png"));
	m_background.setTexture(m_background_texture);

	m_load_widgets();
	m_load_text_box();
}

void NewSheet2::m_event_handler(){
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
				*m_current_tab = "NewSheet";
				m_first_load = true;
				m_window->close();
			}
			else if (m_buttons[1]->check_click(mouse_pos)) {
				std::ofstream myfile;
				myfile.open("C:\\Users\\39348\\scheda1.txt");
				myfile <<"hp:"<<m_stats->Vita << std::endl;
				myfile << "CA:" << m_stats->armorclass << std::endl;
				myfile << "speed:" << m_stats->speed << std::endl;
				myfile << "nome:" << m_stats->Nome << std::endl;
				myfile << "esaustione:" << m_stats->exhaustion << std::endl;
				myfile << "vantaggio:" << m_stats->vantaggio << std::endl;
				myfile << "svantaggio:" << m_stats->svantaggio << std::endl;
				myfile << "accecato:" << m_stats->blinded << std::endl;
				myfile << "charmato:" << m_stats->charmed << std::endl;
				myfile << "assordato:" << m_stats->deafned << std::endl;
				myfile << "spaventato:" << m_stats->frightened << std::endl;
				myfile << "grapplato:" << m_stats->grappled << std::endl;
				myfile << "incapacitato:" << m_stats->incapacitated << std::endl;
				myfile << "invisibile:" << m_stats->invisible << std::endl;
				myfile << "paralized:" << m_stats->paralized << std::endl;
				myfile << "petrifid:" << m_stats->petrified << std::endl;
				myfile << "avvelenato:" << m_stats->poisoned << std::endl;
				myfile << "prono:" << m_stats->prone << std::endl;
				myfile << "restrained:" << m_stats->restrained << std::endl;
				myfile << "stunned:" << m_stats->stunned << std::endl;
				myfile << "svenuto:" << m_stats->unconscious << std::endl;
				myfile.close();
			}

			for (const auto& textinput : m_text_input) textinput->check_click(mouse_pos);

			for (const auto& roundcheck : m_round_check_box) roundcheck->check_click(mouse_pos);
		}
		if (event.type == sf::Event::KeyPressed) {

		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.text.unicode == 4294967295) {
				//caps lock
			}

			if (event.text.unicode <= 25) {
				char pressed_letter = static_cast<char>(event.text.unicode + 0x41);;

				if (is_caps && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);
				if (!is_caps && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) pressed_letter = tolower(pressed_letter);
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
				std::cout << "[Debug] Key: " << event.text.unicode << std::endl;
				break;
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

void NewSheet2::main(){
	if (m_first_load) {
		call_on_load();
		m_first_load = false;
	}

	m_event_handler();

	m_window->clear(sf::Color::Black);
	m_window->draw(m_background);

	for (const auto& button : m_buttons) button->draw(m_window);
	for (const auto& textinput : m_text_input) textinput->draw(m_window);
	for (const auto& roundcheck : m_round_check_box) roundcheck->draw(m_window);
	for (const auto& textoutput : m_text_output) textoutput->draw(m_window);


	m_window->display();


}
