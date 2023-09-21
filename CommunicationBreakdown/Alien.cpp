#include "Alien.h"

Alien::Alien(Room room)
{
	currentRoom_ = room;
}

void Alien::changeRoom(Room nextRoom)
{
	currentRoom_.removeAlien(this);
	currentRoom_ = nextRoom;
}

void Alien::Death()
{
	currentRoom_.removeAlien(this);
	isAlive_ = false;
}
