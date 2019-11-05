#include "Climbing.h"

Climbing::Climbing()
{
}

Climbing::~Climbing()
{
}

void Climbing::idle(Animation* a)
{
	std::cout << "Climbing -> Idling" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Climbing::jumping(Animation* a)
{
	std::cout << "Climbing -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
