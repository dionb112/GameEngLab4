//@author Dion Buckley
#ifndef ANIMATION
#define ANIMATION

#include "Idle.h"

class Animation
{
	class State * current;
public:
	Animation();
	void setCurrent(State * s) { current = s; }
	void idle();
	void climbing();
	void falling();
	void jumping();
	void walking();
};

#endif //!ANIMATION