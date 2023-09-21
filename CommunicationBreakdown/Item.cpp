#include "Item.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

// ITEM SECTION

// Players items with a tied function, quantity and desc
Item::Item(std::string name, std::string description, int count, std::function<int()> behaviour) {
	name_ = name;
	description_ = description;
	count_ = count;
	behaviour_ = behaviour;
}

// Getters
std::string Item::getName()
{
	return name_;
}

std::string Item::getDescription()
{
	return description_;
}