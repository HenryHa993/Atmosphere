#include "Item.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

// ITEM SECTION

// Players items with a tied function, quantity and desc
Item::Item(std::string command, std::string description, int count, bool pickup, std::function<int()> fn) {
	command_ = command;
	description_ = description;
	count_ = count;
	pickup_ = pickup;
	behaviour = fn;
}

// Getters
std::string Item::get_command()
{
	return command_;
}

std::string Item::get_description()
{
	return description_;
}

int Item::get_count()
{
	return count_;
}

