#pragma once
#include <iostream>
#include <string>

struct Stats {
	std::string Nome;//
	std::string NomeGiocatore;
	std::string Classe;
	std::string Livello;
	std::string Razza;
	std::string BackGround;
	std::string Bonus;
	std::string Velocità;
	std::string Iniziativa;
	std::string Vita;

	std::string Forza;
	std::string Destrezza;
	std::string Costituzione;
	std::string Intelligenza;
	std::string Saggeza;
	std::string Carisma;
	std::string ModFor;
	std::string ModDes;
	std::string ModCos;
	std::string ModInt;
	std::string ModSag;
	std::string ModCar;

	std::string SpellSaveDc;
	std::string DadiVita;

	bool m_ability_check_acrobazia = false;
	bool m_ability_check_animali = false;
	bool m_ability_check_arcana = false;
	bool m_ability_check_atletica = false;
	bool m_ability_check_furtività = false;
	bool m_ability_check_indagare = false;
	bool m_ability_check_inganno = false;
	bool m_ability_check_intimidire = false;
	bool m_ability_check_intrattenere = false;
	bool m_ability_check_intuizione = false;
	bool m_ability_check_medicina = false;
	bool m_ability_check_natura = false;
	bool m_ability_check_percezione = false;
	bool m_ability_check_persuasione = false;
	bool m_ability_check_rapidità = false;
	bool m_ability_check_religione = false;
	bool m_ability_check_sopravvivenza = false;
	bool m_ability_check_storia = false;

	bool m_sav_throw_str = false;
	bool m_sav_throw_dex = false;
	bool m_sav_throw_con = false;
	bool m_sav_throw_int = false;
	bool m_sav_throw_wis = false;
	bool m_sav_throw_cha = false;


	int m_hp = 0;//
	int armorclass; 
	int speed;
	int exhaustion = 0;
	bool vantaggio = false, svantaggio = false;
	bool blinded = false;
	bool charmed = false;
	bool deafned = false;
	bool frightened = false;
	bool grappled = false;
	bool incapacitated = false;
	bool invisible = false;
	bool paralized = false;
	bool petrified = false;
	bool poisoned = false;
	bool prone = false;
	bool restrained = false;
	bool stunned = false; 
	bool unconscious = false;




	int m_lvl;
	int m_bonus;
	int	m_hitdice;
	int m_savedc;


	int Str;
	int Dex;
	int Con;
	int Int;
	int Wis;
	int Cha;
	int StrMod = (Str / 2) - 5;
	int DexMod = (Dex / 2) - 5;
	int ConMod = (Con / 2) - 5;
	int IntMod = (Int / 2) - 5;
	int WisMod = (Wis / 2) - 5;
	int ChaMod = (Cha / 2) - 5;
};