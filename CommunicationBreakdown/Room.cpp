#include "Room.h"

Room::Room()
{
	name_ = "";
	//aliens_ = {};
}

Room::Room(std::string name)
{
	name_ = name;
	//aliens_ = {};
}

std::string Room::getName()
{
	return name_;
}

std::string Room::getDescription()
{
	return description_;
}

void Room::setName(const std::string name)
{
	name_ = name;
}

void Room::setDescription(const std::string description)
{
	description_ = description;
}

// Are all aliens dead?
bool Room::areAliensDead()
{
	for (Alien alien : aliens_)
	{
		if (alien.isAlive())
		{
			return false;
		}
	}

	return true;
}


// If the room is occupied with aliens (not dead), then returns true
bool Room::isOccupied()
{
	return aliens_.empty() || areAliensDead();
}

// Return number of live aliens occupying a room
int Room::countAliens()
{
	//int len = aliens_.size();
	//return len;
	int count = 0;

	for (Alien alien : aliens_)
	{
		if (alien.isAlive())
		{
			count++;
		}
	}

	return count;
}