#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
class Component {
public:
	virtual ~Component();
protected:
	Component() {};
};