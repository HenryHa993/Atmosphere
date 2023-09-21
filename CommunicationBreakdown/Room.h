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

	// We using only one alien :( so these are likely unused
	bool areAliensDead();
	bool isOccupied();
	int countAliens();
	//void removeAlien(Alien alien);

private:
	std::string name_;
	std::string description_;
	std::string motion_;
	// We using only one alien :( so this is likely unused
	std::vector<Alien*> aliens_;
};

