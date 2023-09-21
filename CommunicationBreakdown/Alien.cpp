#include "Alien.h"

Alien::Alien(Room room)
{
	currentRoom_ = room;
}

void Alien::changeRoom(Room nextRoom)
{
	//currentRoom_.removeAlien(this);
	currentRoom_ = nextRoom;
}

Room Alien::check_room()
{
	return currentRoom_;
}

void Alien::Death()
{
	//currentRoom_.removeAlien(this);
	isAlive_ = false;
}
