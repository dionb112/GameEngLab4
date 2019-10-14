#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
class Component {
public:
	virtual ~Component();
protected:
	Component() {};
};