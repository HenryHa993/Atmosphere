#include "Player.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

// PLAYER
int MAX_HEALTH = 4;

Player::Player(int health, std::vector<Item> inventory)
{
	health_ = health;
	inventory = inventory;
}

// Lists all inventory items with their description
std::string Player::check_inventory() {
	std::cout << "You take a look in your bag and find some items" << std::endl << std::endl;
	for (auto it = inventory.begin(); it < inventory.end(); it++) {
		Item item = *it;
		std::cout << "  ||  " << "<" << item.get_command() << "> " << item.get_count() << std::endl;
		std::cout << "  ||  " << item.get_description() << std::endl << std::endl;
	}
	//output command success
	return " ";
}

// Adds an item to your inventory
void Player::add_item(Item item) {
	inventory.push_back(item);
}

// Print health
int Player::check_health() {
	return health_;
}
// Change health
void Player::change_health(int modifier) {
	if (modifier > 0 && health_ == MAX_HEALTH)
	{
		std::cout << "player is already at max health";
	}
	health_ += modifier;
	if (health_ == 0)
	{
		std::cout << "oh no! you died!";
	}
}

std::string checkMotion();
//{
//	std::string eastBlip = "x";
//	std::string westBlip = "x";
//	std::string northBlip = "x";
//	std::string southBlip = "x";

//	std::cout << "             " + northBlip + "\n";
//	std::cout << "             N\n";
//	std::cout << "             ^\n";
//	std::cout << "             |\n";
//	std::cout << "             |\n";
//	std::cout << "  " + westBlip + " W <-------------> E " + eastBlip + "\n";
//	std::cout << "             |\n";
//	std::cout << "             |\n";
//	std::cout << "             v\n";
//	std::cout << "             E\n";
//	std::cout << "             " + southBlip + "\n";
//}

//string Player::command(string command) {
//	switch (command) {
//		case health:
//			inventory
//	}
//}

