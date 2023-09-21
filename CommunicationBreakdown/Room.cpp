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
	//aliens_ = {};
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
	return aliens_;
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