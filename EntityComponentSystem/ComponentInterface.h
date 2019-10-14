#pragma once
#include "SFML/Graphics.hpp"
class Component {
public:
	virtual ~Component();
	virtual void foo() = 0;
protected:
	Component();
};