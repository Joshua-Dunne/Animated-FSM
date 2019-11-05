#pragma once
#include "State.h"
#include "Animation.h"

class Climbing : public State
{
public:
	Climbing();
	~Climbing();
	void idle(Animation* a);
	void jumping(Animation* a);
};

