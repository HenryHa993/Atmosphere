#pragma once
#include <string>
#include <vector>
#include <functional>
#include "Item.h"

//using namespace std;

class Player
{
public:
	Player();
	Player(int health, std::vector<Item> inventory);
	//inventory
	std::string checkInventory();
	void addItem(Item item);
	void checkHealth();
	std::string checkMotion();
	void changeHealth(int modifier);
	void command(std::string command);
private:
	std::vector<Item> inventory_;
	int health_;
};