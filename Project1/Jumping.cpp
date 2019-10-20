#include "Jumping.h"

Jumping::Jumping()
{
}

Jumping::~Jumping()
{
}

void Jumping::idle(Animation * a)
{
	a->setCurrent(new Idle());
	delete this;
}
