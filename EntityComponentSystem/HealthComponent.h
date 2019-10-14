#pragma once
#include "ComponentInterface.h"
class HealthComponent : public Component {
public:
	HealthComponent() : m_health(100) {}
	// Data only
	int getHealth() { return m_health; }
	void setHealth(int t_health) { this->m_health = t_health; }
private:
	int m_health;
};