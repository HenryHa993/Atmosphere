#include "Alien.h"

Alien::Alien(std::string description)
{
	isAlive_ = true;
	description_ = description;
}

//void Alien::changeRoom(Room nextRoom)
//{
//	//currentRoom_.removeAlien(this);
//	currentRoom_ = nextRoom;
//}
//
//Room Alien::check_room()
//{
//	return currentRoom_;
//}

bool Alien::isAlive()
{
	return isAlive_;
}


void Alien::Death()
{
	//currentRoom_.removeAlien(this);
	isAlive_ = false;
}
