#pragma once
#include "ComponentInterface.h"
class PositionComponent : public Component {
public:
	PositionComponent() : m_position{ 100, 100, NULL, NULL } { }
	// Data only
	SDL_Rect getPosition() { return m_position; }
	void setPosition(SDL_Rect t_position) { this->m_position = t_position; }
private:
	SDL_Rect m_position;
};