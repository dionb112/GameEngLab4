#include "Falling.h"

Falling::Falling()
{
}

Falling::~Falling()
{
}

void Falling::idle(Animation * a)
{
	a->setCurrent(new Idle());
	delete this;
}
