#include "Climbing.h"

Climbing::Climbing()
{
}

Climbing::~Climbing()
{
}

void Climbing::idle(Animation * a)
{
	a->setCurrent(new Idle());
	delete this;
}
