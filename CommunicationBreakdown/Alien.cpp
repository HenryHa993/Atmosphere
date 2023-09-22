#include "Alien.h"

Alien::Alien(std::string description)
{
	isAlive_ = true;
	description_ = description;
	moved = false;
}

// Is the alien alive?
bool Alien::isAlive()
{
	return isAlive_;
}

// Kill alien
void Alien::Death()
{
	isAlive_ = false;
}
