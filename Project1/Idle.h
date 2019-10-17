#ifndef IDLE
#define IDLE

#include "State.h"
class Animation; //forward reference

class Idle : public State
{
public:
	Idle();
	~Idle();
	void jumping(Animation* a);
	void falling(Animation* a);
	void climbing(Animation* a);
	void walking(Animation* a);
};
#endif // !IDLE
