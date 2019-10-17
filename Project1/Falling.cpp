#include "Falling.h"

Falling::Falling()
{
}

Falling::~Falling()
{
}

void Falling::idle(Animation * a)
{
	std::cout << "To Idle from Falling" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
