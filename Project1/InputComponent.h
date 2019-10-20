#pragma once
#include "ComponentInterface.h"
class InputComponent : public Component {
public:
	InputComponent() : m_input() {}
	// Data only
	SDL_Event getInput() { return m_input; }
	void setInput(SDL_Event t_input) { this->m_input = t_input; }
private:
	SDL_Event m_input;
};