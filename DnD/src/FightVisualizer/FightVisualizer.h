#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "entities/Entity/Entity.h"
#include "entities/WorldEntity/WorldEntity.h"

class FightVisualizer
{

private:
	std::vector<Entity*> entities;
	std::vector<WorldEntity*> world_entities;

	FightVisualizer();
	~FightVisualizer();

	void events_handler();
	void main();
};

