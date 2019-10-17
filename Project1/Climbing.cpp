#include "Climbing.h"

Climbing::Climbing()
{
}

Climbing::~Climbing()
{
}

void Climbing::idle(Animation * a)
{
	std::cout << "To Idle from Climbing" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
