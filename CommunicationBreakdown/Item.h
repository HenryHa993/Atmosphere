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

	std::function<int()> behaviour;

	std::string get_command();
	std::string get_description();
private:
	std::string command_;
	std::string description_;
	int count_;
};