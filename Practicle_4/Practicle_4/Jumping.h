#pragma once
#include "State.h"
#include "Animation.h"

class Jumping : public State
{
public:
	Jumping();
	~Jumping();
	void idle(Animation* a);
	void climbing(Animation* a);
	void falling(Animation* a);
	void landing(Animation* a);
};

