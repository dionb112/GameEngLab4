#pragma once
#include "ComponentInterface.h"
class Entity {
int id;
public:
	Entity() : id{ -1 } {}; // init id to -1 for now (not in notes)
	void addComponent(Component c) { components.push_back(c); };
	void removeComponent(Component c) { /* implement */ };
	std::vector<Component> getComponents() { return components; }
private:
	std::vector<Component> components;
};