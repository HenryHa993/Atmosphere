// OOP Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>
#include <chrono>

#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "Alien.h"

using namespace std;
int main()
{
	cout << "\n\n";
	cout << " ___________________________________________________________________________________________________________________\n";
	cout << "|                                                                                                                   |\n";
	cout << "|     _______    _______    _______    _______     ______    ______     _     _    _______    ______     _______    |\n";
	cout << "|    (_______)  (_______)  (_______)  (_______)   / _____)  (_____ \\\   ( )   ( )  (  _____)  (_____ \\\   (_______)   |\n";
	cout << "|     _______       _       _  _  _    _     _   ( (____     _____) )  | |___| |  | |____      _____)   ) _____     |\n";
	cout << "|    |  ___  |     | |     | ||_|| |  | |   | |   \\\____ \\\   |  ____/   |  ___  |  |  ___)    |  __  /   |  ___)     |\n";
	cout << "|    | |   | |     | |     | |   | |  | |___| |   _____) )  | |        | |   | |  | |_____   | |  \\\ \\\   | |_____    |\n";
	cout << "|    |_|   |_|     |_|     |_|   |_|   \\\_____/   (______/   |_|        |_|   |_|  |_______)  |_|   |_|  |_______)   |\n";
	cout << "|                                                                                                                   |\n";
	cout << "|___________________________________________________________________________________________________________________|\n";
	cout << "\n\n";

	cout << "\t _____________________________________\n";
	cout << "\t|                                     |\n";
	cout << "\t|    FRIDAY, SEPTEMBER 22ND, 2123.    |\n";
	cout << "\t|_____________________________________|\n";
	cout << "\n";
	cout << "\tMESSAGES:\n\n";
	cout << "\tFROM:      COMMANDER WHITE\n";
	cout << "\tTO:        UNITED TERRA SPACE COMMAND\n";
	cout << "\tSUBJECT:   MISSION CRITICAL\n\n";
	cout << "\tBODY:      URGENT MESSAGE. SPECIMEN_NOVUS IS NO LONGER DORMANT. FAIL-SAFE CONTINGENCIES 1 - 3 HAVE FAILED.\n";
	cout << "\t\t   COMMANDING OFFICER WHITE ON ROUTE TO TRIGGER FAIL-SAFE 4, STATION DESTRUCTION. \n ";
	cout << "";
	cout << "";
	cout << "";
	cout << "";
	cout << "";


	// Initialising the player
	auto player = Player(5, vector<Item> {	});

	// Initialising the player inventory
	// []() -> making a lambda function
	player.add_item(Item("sensor", "This can detect mortal danger from far away", 1, [&]()
		{
			cout << "you attempt to use the scanner\n" << endl;
			return 0;
		}));
	player.add_item(Item("healthpack", "This item will restore 1 point of health", 1, [&]()
		{
			player.change_health(1);
			cout << "player health is now " << player.check_health() << endl << endl;
			return 0;
		}));




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

	// TESTING ALIEN
	Alien john = Alien("This guy is bananas");

	int playerMoves;
	auto start_time = std::chrono::high_resolution_clock::now(); // TIMER STARTS NOW

	do
	{
		// ALIEN TESTING
		auto current_time = std::chrono::high_resolution_clock::now();
		std::cout << "Time till atmospheric entry: " << 360 - std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count() << " seconds.\n";

		// MAIN COMMANDS CHECKING
		std::cout << "> ";
		std::cin >> command;
		//add commands here
		if (command == "bag") 
		{
			player.check_inventory();
		}
		else if (command == "look") {
			std::cout << "Looking around "
				+ current->getName()
				+ " you see " + current->getDescription()
				+ "\n";
		} else if (command == "health") {
			cout << "your health is at: " << player.check_health() << endl << endl;
		}
		else if (current->linked_rooms.find(command) != current->linked_rooms.end())
		{
			current = current->linked_rooms[command];
		}
		else // Add more commands via an else if
		{
			bool success = false;
			for (auto it = player.inventory.begin(); it < player.inventory.end(); ++it)
			{
				Item item = *it;
				if (command == item.get_command())
				{
					item.behaviour();
					success = true;
				}
			}
			if (success == true)
			{
				continue;
			} else
			{
				std::cout << "You shake your head in confusion\n";
			}
		}
	} while (command != "exit");


}
