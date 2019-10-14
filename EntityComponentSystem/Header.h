#pragma once
#include "ComponentInterface.h"
class PositionComponent : public Component {
public:
	PositionComponent() : m_position(100) {}
	// Data only
	sf::Vector2f getPosition() { return m_position; }
	void setPosition(sf::Vector2f t_position) { this->m_position = t_position; }
private:
	sf::Vector2f m_position;
};