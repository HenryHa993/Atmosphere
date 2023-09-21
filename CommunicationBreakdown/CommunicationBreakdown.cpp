// OOP Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>

#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "Alien.h"

int Banana()
{
	return 0;
}

using namespace std;
int main()
{
	cout << "Welcome to SPACE GAME, press enter to start ..";
	cin;

	cout << "You awake and feel the cold metal floor below you. An industrial light in the corner of the room is flickering on and off.\n";
	cout << "A gut-wrenching scream from somewhere in the northeast direction rings out and sends shivers down your spine\n";
	cout << "Your head was hurt so you cannot remember what items you had on you\nType <bag> to look in your inventory\n";

	Player player1 = Player(5, vector<Item> {});
	auto test = [&]() {return 0;};
	// Initialising the player's inventory
	// []() -> making a lambda function
	Player player = Player(5, vector<Item> {
		Item("sensor", "This can detect mortal danger from far away\nTo use this item, type <sensor>", 1, test),
		Item("health", "This item will restore 1 point of health\nTo use this item, type <health>", 1, [&]()
			{
				player.checkHealth();
				return 0;
			})/*,
				Item("Torch", "This can illuminate a dark area\nTo use this item, type <torch>", 1, [](Player* p)
				{
					cout << "you use the torch to light the room";
					return 0;
				}),
				Item("Metal scrap", "A piece of metal scrap\nTo use this item, type <scrap>", 5, Banana)*/
	});

	// Pass number to object function -> Feedback


	//#####// CREATING ROOMS //#####//	

	// Room roomName = Room("Room Name");
	// roomName.setDescription("");

	Room kitchen = Room("The Kitchen (Residential Zone)");
	kitchen.setDescription("");

	Room messRoom = Room("Mess Room (Residential Zone)");
	messRoom.setDescription("");

	Room spaceGym = Room("Space Gym (Residential Zone)");
	spaceGym.setDescription("");

	Room resiCorridor = Room("Corridor (Residential Zone)");
	resiCorridor.setDescription("");

	Room crewQuarters = Room("Crew Quarters (Residential Zone)");
	crewQuarters.setDescription("");

	Room office = Room("Commander's Office (Residential Zone)");
	office.setDescription("");

	Room washRoom = Room("Wash Room (Residential Zone)");
	washRoom.setDescription("");

	Room equipmentBay = Room("Equipment Bay (Residential Zone)");
	equipmentBay.setDescription("");

	Room cargoBay = Room("Cargo Bay (Utility Zone)");
	cargoBay.setDescription("");

	Room escapeBay = Room("Escape Pod Bay (Utility Zone)");
	escapeBay.setDescription("");

	Room repairBay = Room("Repair Bay (Science Zone)");
	repairBay.setDescription("");

	Room sciCorridor = Room("Corridor (Science Zone)");
	sciCorridor.setDescription("");

	Room labOne = Room("Science Lab 01 (Science Zone)");
	labOne.setDescription("");

	Room labTwo = Room("Science Lab 02 (Science Zone)");
	labTwo.setDescription("");

	Room monStation = Room("Monitoring Station (Science Zone)");
	monStation.setDescription("");

	Room trashEject = Room("Trash Ejector (Science Zone)");
	trashEject.setDescription("");

	Room medBay = Room("Medical Bay (Science Zone)");
	medBay.setDescription("");

	Room hazmat = Room("Hazardous Materials (Science Zone)");
	hazmat.setDescription("");


	//#####// LINKING ROOMS //#####//

	//roomName.linked_rooms["diresction"] = &roomName;

	// UTILITY ZONE //
	cargoBay.linked_rooms["north"] = &equipmentBay;
	cargoBay.linked_rooms["east"] = &escapeBay;
	cargoBay.linked_rooms["south"] = &repairBay;

	escapeBay.linked_rooms["west"] = &cargoBay;

	// RESIDENTIAL ZONE //
	equipmentBay.linked_rooms["north"] = &resiCorridor;
	equipmentBay.linked_rooms["south"] = &cargoBay;

	crewQuarters.linked_rooms["north"] = &office;
	crewQuarters.linked_rooms["east"] = &resiCorridor;
	crewQuarters.linked_rooms["west"] = &washRoom;

	washRoom.linked_rooms["east"] = &crewQuarters;

	office.linked_rooms["east"] = &spaceGym;
	office.linked_rooms["south"] = &crewQuarters;

	spaceGym.linked_rooms["south"] = &resiCorridor;
	spaceGym.linked_rooms["west"] = &office;

	resiCorridor.linked_rooms["north"] = &spaceGym;
	resiCorridor.linked_rooms["east"] = &messRoom;
	resiCorridor.linked_rooms["south"] = &equipmentBay;
	resiCorridor.linked_rooms["west"] = &crewQuarters;

	messRoom.linked_rooms["south"] = &kitchen;
	messRoom.linked_rooms["west"] = &resiCorridor;

	kitchen.linked_rooms["north"] = &messRoom;

	// SCIENCE ZONE //  
	repairBay.linked_rooms["north"] = &cargoBay;
	repairBay.linked_rooms["south"] = &sciCorridor;
	repairBay.linked_rooms["west"] = &hazmat;

	hazmat.linked_rooms["east"] = &repairBay;
	hazmat.linked_rooms["south"] = &medBay;

	medBay.linked_rooms["north"] = &hazmat;
	medBay.linked_rooms["east"] = &sciCorridor;

	sciCorridor.linked_rooms["north"] = &repairBay;
	sciCorridor.linked_rooms["east"] = &labOne;
	sciCorridor.linked_rooms["south"] = &trashEject;
	sciCorridor.linked_rooms["west"] = &medBay;

	trashEject.linked_rooms["north"] = &sciCorridor;
	trashEject.linked_rooms["east"] = &monStation;

	monStation.linked_rooms["north"] = &labOne;
	monStation.linked_rooms["west"] = &trashEject;

	labOne.linked_rooms["east"] = &labTwo;
	labOne.linked_rooms["south"] = &monStation;
	labOne.linked_rooms["west"] = &sciCorridor;

	labTwo.linked_rooms["west"] = &labOne;


	Room* current = &cargoBay;
	std::string command;

	// Testing the aliens
	Alien john = Alien(cargoBay);
	std::cout << "cargo bay count" + cargoBay.alienCount();
	std::cout << "";

	do
	{

		std::cout << "Looking around "
			+ current->getName()
			+ " you see " + current->getDescription()
			+ "\n";
		std::cout << "> ";
		std::cin >> command;
		//add commands here
		if (current->linked_rooms.find(command) != current->linked_rooms.end())
		{
			current = current->linked_rooms[command];
		}
		else // Add more commands via an else if
		{
			std::cout << "You can't go that way!\n";
		}
	} while (command != "exit");


}