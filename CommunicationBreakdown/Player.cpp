#include "Player.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

// PLAYER

Player::Player(int health, std::vector<Item> inventory)
{
	health_ = health;
	inventory_ = inventory;
}

// Lists all inventory items with their description
std::string Player::checkInventory() {
	std::cout << "You take a look in your bag and find some items" << std::endl;
	for (std::vector<Item>::iterator it = inventory_.begin(); it < inventory_.end(); it++) {
		Item item = *it;
		std::cout << item.getName() << std::endl;
		std::cout << item.getDescription() << std::endl;
	}
	//ouput command success
	return " ";
}

// Adds an item to your inventory
void Player::addItem(Item item) {
	inventory_.push_back(item);
}

// Print health
void Player::checkHealth() {
	std::cout << health_;
}
// Change health
void Player::changeHealth(int modifier) {
	health_ += modifier;
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

