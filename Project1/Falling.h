#ifndef FALLING
#define FALLING

#include "State.h"
class Animation;

class Falling : public State
{
public:
	Falling();
	~Falling();
	void idle(Animation* a);
};

#endif 
