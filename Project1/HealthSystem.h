#pragma once
#include "Entity.h"
class HealthSystem {
	std::vector<Entity> m_entities;
public:
	void addEntity(Entity e);
	void update();
};