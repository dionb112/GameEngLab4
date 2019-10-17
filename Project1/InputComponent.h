#pragma once
#include "ComponentInterface.h"
class InputComponent : public Component {
public:
	InputComponent() : m_input() {}
	// Data only
	sf::Event getInput() { return m_input; }
	void setInput(sf::Event t_input) { this->m_input = t_input; }
private:
	sf::Event m_input;
};