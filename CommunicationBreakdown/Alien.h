#pragma once

#include "Room.h"
#include <iostream>


class Alien
{
public:
	Alien(Room room); // Ah but you don't want two aliens to occupy a room do you?
	void changeRoom(Room nextRoom);
	void Death();
	Room check_room()
;
private:
	bool isAlive_; // Alive status
	Room currentRoom_; // What room it occupies. If we want more aliens to occupy a singular room then this should be used.
	std::string description_; // What the alien looks like
};


