#include <cstdlib>
#include <algorithm>

#include "Room.h"

Room::Room(std::string name, std::string description, std::string look, bool aliens, std::string aliens_text, std::string sensor, std::function<int()> behaviour, std::vector<Item> items)
{
	name_ = name;
	description_ = description;
	look_ = look;
	aliens_ = aliens;
	aliens_text_ = aliens_text;
	sensor_ = sensor;
	behaviour_ = behaviour;
	items_ = items;

	aliensVector_ = {}; // For aliens
}

std::string Room::get_name()
{
	return name_;
}

std::string Room::get_description()
{
	return description_;
}

std::string Room::look()
{
	return look_;
}

void Room::setName(const std::string name)
{
	name_ = name;
}

void Room::setDescription(const std::string description)
{
	description_ = description;
}

std::vector<Item> Room::get_items()
{
	return items_;
}

void Room::remove_item(int position)
{
	items_.erase(items_.begin() + position);
}

// Are all aliens dead?
//bool Room::areAliensDead()
//{
//	for (Alien* alien : aliens_)
//	{
//		if (alien->isAlive())
//		{
//			return false;
//		}
//	}
//
//	return true;
//}


// If the room is occupied with aliens (not dead), then returns true
bool Room::isOccupied()
{
	return !aliensVector_.empty(); // slight change
	//return aliens_;
}

void Room::addAlien(Alien* alien)
{
	aliensVector_.push_back(alien);
}


// Return number of live aliens occupying a room
//int Room::countAliens()
//{
//	//int len = aliens_.size();
//	//return len;
//	int count = 0;
//
//	for (Alien* alien : aliens_)
//	{
//		if (alien->isAlive())
//		{
//			count++;
//		}
//	}
//
//	return count;
//}

// Check if a room is adjacent to another
bool Room::isAdjacent(Room* room)
{
	return (linked_rooms["north"] == room || linked_rooms["east"] == room || linked_rooms["south"] == room || linked_rooms["west"] == room);
}

// Used to randomise alien direction of movement
std::string Room::randomDirection()
{
	int randInt = rand() % 4;
	//std::cout << randInt << "\n";

	switch (randInt)
	{
	case 0:
		return "north";
	case 1:
		return "east";
	case 2:
		return "south";
	case 3:
		return "west";
	default:
		return "north";
	}
}

void Room::moveAlien(Room* room, Alien* alien) // Return std::vector<Alien*> ?
{
	//std::cout << "Moving alien from " << name_;// << " to " << room->name_ << ".\n";

	// Just moved true
	alien->moved = true;

	// Find index of given alien
	std::vector<Alien*>::iterator position = std::find(aliensVector_.begin(), aliensVector_.end(), alien);

	// If position is not null, erase alien from room
	if (position != aliensVector_.end())
		aliensVector_.erase(position);

	// Put alien in new room
	room->aliensVector_.push_back(alien);

	std::cout << "\nWARNING: Unidentified movement detected on the ship.\n";
}

void Room::shuffleAliens(Room* currentRoom)
{
	if (!isOccupied())
	{
		//std::cout << "No alien present in " << name_ << ".\n";
		return;
	}

	for (Alien* alien : aliensVector_)
	{

		//Check just moved

		if (alien->moved)
		{
			//std::cout << "Alien moved into " << name_ << " this round.\n";
			continue;
		}

		// Not moved, so move it
		if (isAdjacent(currentRoom))
		{
			moveAlien(currentRoom, alien);
		}
		else
		{
			// Randomised alien placements
			std::string movement;
			movement = randomDirection();

			// Does not work
			//std::cout << "CHECK : " << (linked_rooms.find(movement) == linked_rooms.end()) << "\n";
			while (linked_rooms[movement] == nullptr)//!isAdjacent(linked_rooms[movement]))// linked_rooms.find(movement) == linked_rooms.end())
			{
				//std::cout << "Generated new movement: " << movement << "\n";
				movement = randomDirection();
			}

			moveAlien(linked_rooms[movement], alien);
			// Randomise movement
		}

	}
}
