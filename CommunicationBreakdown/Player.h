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
	std::string check_inventory();
	bool has_item(std::string command);
	std::vector<Item> inventory;
	void add_item(Item item);
	int check_health();
	std::string checkMotion();
	void change_health(int modifier);
	void command(std::string command);
private:
	int health_;
};