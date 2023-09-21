#pragma once
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

class Item
{
public:
	Item();
	Item(std::string command, std::string description, int count, std::function<int()> behaviour);

	std::string getName();
	std::string getDescription();

	std::function<int()> behaviour_;
private:
	std::string name_;
	std::string description_;
	int count_;
};