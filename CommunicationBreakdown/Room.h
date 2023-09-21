#pragma once

#include <map>
#include <string>
#include <vector>

#include "Alien.h"

class Room
{
public:
	Room();
	Room(std::string name);
	std::map <std::string, Room*> linked_rooms = {};

	std::string getName();
	std::string getDescription();

	void setName(const std::string name);
	void setDescription(const std::string description);

	bool areAliensDead();
	bool isOccupied();
	int countAliens();
	//void removeAlien(Alien alien);

private:
	std::string name_;
	std::string description_;
	std::string motion_;
	std::vector<Alien> aliens_; // Should a single alien occupy a room?
};

