#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#ifdef _WIN64
#include <Windows.h>
#endif

#pragma warning(disable : 4996)

#define TILE_TYPES 9

#define DEBUG_ENTITIES 0
#define DEBUG_WIDGETS 0

namespace globals {
	inline std::string userprofile;
	inline std::map<std::string, sf::Font*> fonts;

	__forceinline std::string get_assets_path(const std::string& path_from_assets_folder) {
		if (userprofile.empty()) {
			userprofile = std::string(getenv("USERPROFILE"));
		
		}
		std::string absolute_path =  userprofile + "\\source\\repos\\DnD\\DnD\\assets\\" + path_from_assets_folder;
		return absolute_path;
	}
}


