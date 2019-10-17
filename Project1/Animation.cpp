//@author Dion Buckley
#include "Animation.h"

Animation::Animation()
{
	current = new Idle();
}

void Animation::idle()
{
	current->idle(this);
}

void Animation::climbing()
{
	current->climbing(this);
}

void Animation::falling()
{
	current->falling(this);
}

void Animation::jumping()
{
	current->jumping(this);
}

void Animation::walking()
{
	current->walking(this);
}

