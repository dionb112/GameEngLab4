#include "Walking.h"

Walking::Walking()
{
}

Walking::~Walking()
{
}

void Walking::idle(Animation * a)
{
	a->setCurrent(new Idle());
	delete this;
}
