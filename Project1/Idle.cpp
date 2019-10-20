//@author Dion Buckley

#include "Idle.h"
#include <iostream>

Idle::Idle()
{
}

Idle::~Idle()
{
}

void Idle::jumping(Animation * a)
{
	a->setCurrent(new Idle());
	delete this;
}

void Idle::falling(Animation * a)
{
	a->setCurrent(new Idle());
	delete this;
}

void Idle::climbing(Animation * a)
{
	a->setCurrent(new Idle());
	delete this;
}

void Idle::walking(Animation * a)
{
	a->setCurrent(new Idle());
	delete this;
}
