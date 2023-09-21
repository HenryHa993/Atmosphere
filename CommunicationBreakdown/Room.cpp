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

// Functions to do with aliens

//void Room::removeAlien(Alien alien)
//{
//	aliens_.erase(std::remove(aliens_.begin(), aliens_.end(), alien), aliens_.end());
//}
//
//
//// If the room is occupied with aliens (not dead), then returns true
//bool Room::isOccupied()
//{
//	return aliens_.empty() || areAliensDead();
//}
//
//// Return number of live aliens occupying a room
//int Room::alienCount()
//{
//	int len = aliens_.size();
//	return len;
//}
