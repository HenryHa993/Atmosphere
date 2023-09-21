#include "Room.h"

Room::Room()
{
	name_ = "";
}

Room::Room(std::string name)
{
	name_ = name;
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
