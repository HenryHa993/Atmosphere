#pragma once

#include <map>
#include <string>
#include <vector>
#include <functional>

#include "Alien.h"
#include "Item.h"

class Room
{
public:
	Room();
	Room(std::string name, std::string description, std::string look, bool aliens, std::string aliens_text, std::string sensor, std::function<int()> behaviour, std::vector<Item> items);

	std::map <std::string, Room*> linked_rooms = {};

	std::string get_name();
	std::string get_description();
	std::string look();
	std::vector<Item> get_items();
	void remove_item(int position);

	void setName(const std::string name);
	void setDescription(const std::string description);

	//bool areAliensDead();
	bool isOccupied();
	void addAlien(Alien* alien);
	//int countAliens();
	//void removeAlien(Alien alien);

	std::string randomDirection();
	void moveAlien(Room* currentRoom, Alien* alien);
	bool isAdjacent(Room* room); // Check if room is adjacent to another
	void shuffleAliens(Room* currentRoom);

private:
	std::string name_;  // ..
	std::string description_; // ..
	std::string sensor_; // a piece of text displayed when the <sensor> command is used
	std::string look_; // a piece of text displayed when the <look> command is used

	bool aliens_;
	std::string aliens_text_;
	std::function<int()> behaviour_;
	std::vector<Item> items_;
	
	std::vector<Alien*> aliensVector_;
};

