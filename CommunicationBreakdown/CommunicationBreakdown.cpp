// OOP Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>
#include <chrono>
#include <windows.h>

#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "Alien.h"

using namespace std;
int main()
{
	bool intro = PlaySound(L"atmosphere.wav", NULL,SND_LOOP | SND_ASYNC);

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
	cout << "Press ENTER to start";
	cin.get();

	cout << "\n\n\nYou awake and feel the cold metal floor below you. An industrial light in the corner of the room is flickering on and off.\n";
	cout << "A gut-wrenching scream from somewhere in the northeast direction rings out and sends shivers down your spine\n";
	cout << "Your head was hurt so you cannot remember where you are\n\nType <look> to take note of your surrounding and <bag> to check your inventory\n";

	// Initialising the player
	auto player = Player(3, vector<Item> {	});

	// Pass number to object function -> Feedback

	player.add_item(Item("scrap", "A useless piece of metal scrap", 5, 0, []() {cout << "you atttempt to use the metal scrap"; return 0; }));

	//#####// CREATING ROOMS //#####//	

	// Room roomName = Room("Room Name", "text displayed on entering", alienBool, "text displayed if alien", "text displayed with sensor", behaviour lambda, items vector);

	//Room("", "", "", 0, "", "", []() {return 0; }, empty_vector);
	vector<Item> empty_vector;
	Room kitchen = Room("The Kitchen (Residential Zone)",
		"The Kitchen is a mess. You cannot sense any movement.\nThe chef's body is lying in the corner with something alien clasped to his torso.\nWater is overflowing from the sink onto the floor. Is the sound of water masking any other sounds?\nyou're not sure, you might be hearing things...\n\n",
		"", 0, "An alien is sat on the metal worksurface. It jumps at you and bites down hard on your right forearm. You wrestle you arm free, your overall arm remains in the jaws of the alien.",
		"", []() {return 0; }, empty_vector);

	//Room("", "", "", 0, "", "", []() {return 0; }, empty_vector);
	Room messRoom = Room("Mess Room (Residential Zone)", 
		"You are in the Mess Room. The well worn sofas which have been moulded by crew members are now covered in their entrails.\nIt looks like a desperate struggle took place here. You notice that the cerebral reality connectors lie on the floor.\nYou wish you could spend some time at your favourite virtual holiday destination.\n\n", 
		"", 0, "", "", []() {return 0; }, empty_vector);

	Room spaceGym = Room("Space Gym (Residential Zone)", 
		"The Space Gym is eerily quiet. Exercise equipment sits unused, and holographic workout routines play on repeat.\nLights torn from the ceiling create a strobe like effect. Slick pools of black liquid on the floor stick to your boots.\nA pair of hands remain attached to a barbell, severed at the bone.\n\n", 
		"", 0, "As you enter you hear a raspy breath, it isnt a human. In the shadows you see the head of an alien turn and sniff the air. It catches your scent, it twists around and releases 2 bone darts from its spine. You hear two thuds, one dart is in the wall behind you the other is embeded in your spleen.\n", 
		"", []() {return 0; }, {
		});

	Room resiCorridor = Room("Corridor (Residential Zone)", 
		"The residential corridor stretches on seemingly forever.\nThe walls are scuffed, and no one ever did own up to the graffiti, you have your suspicions though.\n\n", 
		"", 0, "The corridor ceiling grid crashes down, an alien drops from the void above. Screeching wildly, it slashes its long claws across your chest. The attack knocks you to the ground, you groan and scramble to your feet once more.", 
		"", []() {return 0; }, empty_vector);

	Room crewQuarters = Room("Crew Quarters (Residential Zone)", 
		"Crew Quarters are personal and cluttered. Beds are unmade. Wardrobe doors are left open, belongings are left,\nscattered on the floor. Your shipmates must have jumped into action upon hearing the alarms.\n\n", 
		"", 0, "", "", []() {return 0; }, {
		Item("map", "shows the lvel!\n", 1, 0, [&]() { return 0; }),
		});

	Room office = Room("Commander's Office (Residential Zone)", 
		"The Commander's Office is spacious and imposing.\nCommander white is lying face down on his imposingly large desk, in his blood stained uniform.\nHopefully he had a quick death. He had lightning fast reactions,\nso whatever killed him must have been even quicker.\n\n", 
		"", 0, "", "", []() {return 0; }, {
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
		});

	Room washRoom = Room("Wash Room (Residential Zone)", 
		"The Wash Room is sterile and cold. All of the surfaces are a lime green coloured anti-microbial surface.\nThe glazed door of one of the water recycling shower cubicles is covered in blood.\nYou don't feel like opening that cubicle.\n\n", 
		"", 0, "", "", []() {return 0; }, {
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
		});

	Room equipmentBay = Room("Equipment Bay (Residential Zone)",
		"The Equipment Bay is stocked with tools and supplies. Space suits hang from the walls, another has fallen on the floor.\nAs you look closer you realise it contains what remains of Eddy...\nPoor son of a bitch...\n\n",
		"", 0, "", "", []() {return 0; }, { Item("purplekeycard", "Gives you access to the escape pod bay", 1, 1, [&]()
		{
			return 0;
		}) });

	Room cargoBay = Room("Cargo Bay (Utility Zone)", 
		"The Cargo Bay is cavernous, filled with towering crates and containers.\nThe warning light still flickers overhead, casting a faint red light and eerie shadows.\nThe air is stale, and you can't shake the feeling that you're being watched.\n\n", 
		"there are no signs of life here.",
		1, "An alien jumps from the high level gantry. It tries to grab you, you step backwards. The aliens long claws slashe your left left. You whimper and hop out of its reach.\n", "", []() {return 0; }, 
		{Item("sensor", "This can detect mortal danger from far away", 1, 1, [&]()
		{
			cout << "you attempt to use the scanner" << endl;
			return 0;
		}),
	Item("healthpack", "This item will restore 1 point of health", 1, 1, [&]()
		{
			player.change_health(1);
			cout << "player health is now " << player.check_health() << endl << endl;
			return 0;
		}),
		
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
	Item("maintenance_bot_leg", "You look at the leg and think where's the rest of ARNY? This means more cleaning for me!\n", 1, 0, [&]() {return 0; }),
			Item("empty_mineral_container", "You inspect the mineral container, it is empty.\n", 1, 0, [&]() {return 0; }) }
		);
//,
//	Item("keycardscanner", "This item will allow you to access the Escape Pod Bay", 1, 0, [&]()
//		{
//			cout << "You attempt to use the key card scanner" << endl << endl;
//			return 0;
//		})

	Room escapeBay = Room("Escape Pod Bay (Utility Zone)", 
		"You pass through the door into the escape pod bay.\nThe only remaining escape pod control pad is flashing. A sense of relief floods over you.\n\n", 
		"", 0, "", "", [&]() {if (player.has_item("purplekeycard")) { return 0; } else { cout << "you do not have correct keycard to access this room\n"; return 1; } }, 
		{
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
		});

	Room repairBay = Room("Repair Bay (Science Zone)", 
		"The Repair Bay is cluttered with tools, machinery, and partially dismantled equipment.\nBroken robots lie in disrepair. On the far wall, a stainless steel workbench.\nThere is a hammer on the tool rack and a repair engineer lies dead in the corner.\nThere are various wall mounted robotic tools and 3d printers to assist in fixing\nmost things you need on a space station.\nMost of which are now damaged.Several lockers are left open, their doors ripped from the hinges.\nOne locker is in good order, but locked tight.\n\n", 
		"", 0, "", "", []() {return 0; }, {
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
		});

	Room sciCorridor = Room("Corridor (Science Zone)", 
		"The Science Corridor is lined with laboratories, their doors sealed.\nThe once-bustling hub of research is now silent. Equipment hums faintly in the stillness.\nAll the sealed doors are handprint access controlled.\n\n", 
		"", 0, "", "", []() {return 0; }, empty_vector);

	Room labOne = Room("Science Lab 01 (Science Zone)", 
		"Lab 01 is in disarray. Broken vials and shattered glassware are scattered across the floor. The whiteboards \n are covered in a mixture of red and black fluid.\n\n", 
		"", 0, "", "", []() {return 0; }, empty_vector);

	Room labTwo = Room("Science Lab 02 (Science Zone)", 
		"Lab 02 is completely decimated, even compared to the rest of what you've seen on the station so far. The \n carnage you're seeing fills you with dread. The floors are covered in glass, blood and torn lab coats. There's some sort of containment chamber in the center of the room... Well, what remains of one... Something was being kept in there. And it clearly wanted to get out... \n\n", 
		"", 0, "", "", []() {return 0; }, {
	Item("robotic_arm", "You inspect the wall mounted loading arm closely, the hydraulics are shot, you cant believe it this thing was bulletproof!\n", 1, 0, [&]() {return 0; }),
		});

	Room monStation = Room("Monitoring Station (Science Zone)", 
		"The Monitoring Station is a room of screens and consoles. Many screens display static or errors. The few that \n function show unsettling images and data you'd rather not see. Damage to some of the consoles is extensive. The orbit \n management system shows the stations current position and trajectory into the Saturn's atmosphere. Your stomach churns.\n\n", 
		"", 0, "", "", []() {return 0; }, {
		});

	Room trashEject = Room("Trash Ejector (Science Zone)", 
		"The Trash Ejector is a cold, metallic room filled with the clunking of machinery. The room smells bad a mixture \n between rotten synthetic food and cleaning chemicals. There is a huge bulkhead door on the wall opposite you, \n behind you are an array of vacuum pressure jets, you remember that these are what shoots the trash out into space.\n\n", 
		"", 0, "", "", []() {return 0; }, empty_vector);

	Room medBay = Room("Medical Bay (Science Zone)", 
		"You are in the medical bay. Empty beds and scattered medical equipment suggest a hurried evacuation. There's \n a row of stasis pods. One, of which is set to hyper sleep. A bloody handprint stains the inside of the glass.\n\n", 
		"", 0, "", "", []() {return 0; }, {
	Item("a_blood_covered_pelvis", "You guess it's a crew members, but you can't fathom who's it might have belonged to or where the rest of them might be?\n", 1, 0, [&]() {return 0; }),
	Item("stasis_pods", "You look at the stasis pod, it seems to be working?\n", 1, 0, [&]() {return 0; }),
	Item("health_kit", "You examine the health kit, this is your lucky day!\n", 1, 0, [&]() {return 0; }),
		});

	Room hazmat = Room("Hazardous Materials (Science Zone)", 
		"You are in Hazardous Materials. Alarms are sounding and the holo screens flash: 'FAIL-SAFE 04. \n ATMOSPHERIC SELF DESTRUCT SEQUENCE INITIATED'... Fuck... Several of the biological containment vessels are empty \n and open. Gooey footprints on the floor show that something entered this room and \n then left into the station.\n\n", 
		"", 0, "", "", []() {return 0; }, 
		{
	Item("hazmat_suit", "You inspect the suit it has a tear in it. But hey youre probably contaiminated with spors or something already", 1, 0, [&]() {return 0; }),
	Item("biological_samples", "You look at the biological samples, they are sticky ewww!", 1, 0, [&]() {return 0; })});
//	Item("Axe", "That looks sharp... I wonder if I can take out an alien with this bad boy!", 1, 0, [&]() {return 0; })	});

	std::vector<Room*> allRooms = {
	&kitchen,
	&messRoom,
	&spaceGym,
	&resiCorridor,
	&crewQuarters,
	&office,
	&washRoom,
	&equipmentBay,
	&cargoBay,
	&escapeBay,
	&repairBay,
	&sciCorridor,
	&labOne,
	&labTwo,
	&monStation,
	&trashEject,
	&medBay,
	&hazmat
	};

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

	// INITIALISE ALIEN
	// Add aliens here if you want more than one
	Alien john = Alien("This guy is bananas");
	cargoBay.addAlien(&john);

	std::vector<Alien*> allAliens = {&john};

	// INITIALISE MOVE COUNTERS FOR ALIEN MOVEMENT
	int playerMoves = 0;
	int moveInterval = 2;
	int alienMoves = 0;

	// TIMER INITIALISATION
	auto start_time = std::chrono::high_resolution_clock::now(); // TIMER STARTS NOW

	do
	{
		// ALIEN TESTING
		//auto current_time = std::chrono::high_resolution_clock::now();
		//std::cout << "Time till atmospheric entry: " << 360 - std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count() << " seconds.\n";
		//std::cout << "Testing isAdjacent: " << cargoBay.isAdjacent(&equipmentBay);
		//cargoBay.shuffleAliens(current);
		//for (Room* room : allRooms)
		//{
		//	room->shuffleAliens(current);
		//}

		// CHECKING COMMANDS
		std::cout << endl << "> ";
		std::cin >> command;
		//add commands here
		if (command == "bag") 
		{
			player.check_inventory();
		}
		else if (command == "look") {
			std::cout << "\nLooking around the room, you see that you are in the "
				+ current->get_name() + " "
				+ current->look()
				+ "\n";
			auto linked_rooms = current->linked_rooms;
			cout << endl;
			for (auto const& x : linked_rooms)
			{
				std::cout << "To your " << x.first  // string (key)
						  << " you see " 
						  << x.second->get_name() // string's value 
						  << std::endl;
			}
			cout << endl;
			std::cout << "Looking for items you see ";
			bool success = 0;
			auto items = current->get_items();
			for (auto it = items.begin(); it != items.end(); ++it)
			{
				auto item = *it;
				std::cout << item.get_count() + " <" + item.get_command() + "> ";
				success = 1;
			}
			if (success == 0) {
				cout << "nothing.";
			}
		  cout << std::endl;
		} else if (command == "health") {
			cout << "your health is at: " << player.check_health() << endl << endl;
		}
		else if (current->linked_rooms.find(command) != current->linked_rooms.end())
		{
			if (current->linked_rooms[command]->behaviour_() == 0)
			{
				current = current->linked_rooms[command];
				cout << current->get_description();
			}
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
			auto items = current->get_items();
			int count = 0;
			for (auto it = items.begin(); it != items.end();++it)
			{
				auto item = *it;
				if (command == item.get_command())
				{
					if (item.pickup_)
					{
						cout << "You pick up the <" + item.get_command() + "> and add it to your bag\n"
							+ "You can now use this item using <" + item.get_command() + ">\n";
						player.add_item(item);
						current->remove_item(count);
						success = true;
					} else 
					{
						cout << item.get_description() << endl;
						item.behaviour();
						success = true;
					}
				}
				//std::cout << item.get_count() + " <" + item.get_command() + "> ";
				count++;
			}

			if (success)
			{
				continue;
			} else
			{
				std::cout << "You shake your head in confusion\n";
			}
		}

		// ALIEN MOVEMENTS HAPPEN AFTER PLAYER MOVES
		// Player increment counter
		playerMoves++;
		//std::cout << "Player moves: " << playerMoves << ".\n";

		if(alienMoves < playerMoves/moveInterval)
		{
			alienMoves = playerMoves / moveInterval;
			//std::cout << "Alien moves: " << alienMoves << ".\n";
			for (Room* room : allRooms)
			{
				room->shuffleAliens(current);
				// just moved false
			}
		}

		// Reset moved flag on aliens
		for (Alien* alien : allAliens)
		{
			alien->moved = false;
		}

		// IF ALIEN SAME ROOM ATTACKED
		if(current->isOccupied())
		{
			std::cout << "                                                    .                                    \n";
			std::cout << "                                              ..:    :..                                 \n";
			std::cout << "                                              :..~YJ:::!:                                \n";
			std::cout << "                                              7Y5BGBGYP5.                                \n";
			std::cout << "                                              .YPBBBG5Y!                                 \n";
			std::cout << "                                               !PPGBP5?^                                 \n";
			std::cout << "                                               :Y5GYJJ~^.                                \n";
			std::cout << "                                            .^7:?JJJ5^. :^                               \n";
			std::cout << "                                         . .:~!!J?!7:::::7^:..                           \n";
			std::cout << "                                       .. .:::~?5P5?^:.:..   :^                          \n";
			std::cout << "                  ...                  ::~!:.. :?J7:...... .^^7.                         \n";
			std::cout << "                 ^BBGGY^               :.?B5:.:~!.. .....!5^.~?                          \n";
			std::cout << "                ~YBGPP#&B!.           :^7?^Y^:^!. ....^!JG#Y:~!                          \n";
			std::cout << "              .~PPJJJ!!J?BBY:       .^~?: .~^~~~!^:..^!?P5^^:^!                          \n";
			std::cout << "             .^  !^.7!.   .~JJ!:   .!!:   .5?:^:....:.^J~  :^^~                          \n";
			std::cout << "                  Y?~~J^        !J??J:       ?::!~.  :^^~    ^:!                          \n";
			std::cout << "            :    7. .?Y.         7:        .^7^^:.    :~~   ~:7~                         \n";
			std::cout << "           J~....7~  !7.                  :!.:~!^::..^~::^  7~7?                         \n";
			std::cout << "           ?     ~^ ..^.                  :?7!~!~.:!~:....~ !~!!                         \n";
			std::cout << "           ^     ~!   .:                  . .~?~::^?!: :.^!:!^~.                         \n";
			std::cout << "          .!~.. .!!    7                  .  :~??75J^J:..^~.:!7                          \n";
			std::cout << "          :J.    .J    ?.                 :. .:JPP!J?! :^!! ~!!                          \n";
			std::cout << "           5!~!7!75.   !7                 ::.^5JY^  J^  ^~^ !P!                          \n";
			std::cout << "           ^^    .!^   .^                 .:.!~!J   !: .:.: ~#~                          \n";
			std::cout << "            ~      ^.   ~                 .!^^~!!   ^. .... ^#?                          \n";
			std::cout << "            ..      !   !                 .!  ^?~   ^. . .. ~#P                          \n";
			std::cout << "             ^      .~  ^.                 ^ .~~.   .. ..^  ~&#:                         \n";
			std::cout << "              ^      :^ ..                 : .^^     :.^~:  !&#!                         \n";
			std::cout << "              .       ~...                 :. ^~     ^.~?.  ^JP5:                        \n";
			std::cout << "                       .                   .!:~!     ^~7?~   ~PPGJ                       \n";
			std::cout << "                       .                   .^ .~     .^:!5:  :PP#5P~                     \n";
			std::cout << "                                           .J!J!      ..~JY: ^BGPJYB~^                   \n";
			std::cout << "                                           :?!P~      .7!~7! :G7!J55YJ!:                 \n";
			std::cout << "                                           :.^Y^       ^?:...?Y!~YJ?^^7?~:.              \n";
			std::cout << "                                          :~~?!         !777^?::~^~Y!~?Y^7?.             \n";
			std::cout << "                                          ^5YY           ~5G?!  :^?YJ:.^7?^.             \n";
			std::cout << "                                          .B#7            YB5~!:^  ^~:..~G5:             \n";
			std::cout << "                                          .##^            7BG.P^    .Y:!~:!7             \n";
			std::cout << "                                          ^&#:            !##:^? .   !5! ..?:            \n";
			std::cout << "                                          J&&7            Y##? :..7  ..:~^!JG^ ~^        \n";
			std::cout << "                                         :G#BB:          ^#GG5  ...        ~5?^.         \n";
			std::cout << "                                          .:^!7~.       ^?!.                             \n";
			std::cout << "\nA dark, sleek mass enters the room...\n";
			std::cout << "\nIt contorts, twisting and convulsing. It swipes at you with an twisted appendage.\n";

			player.change_health(-1);

			std::cout << "\nYou take 1 damage. Act quickly.\n";
		}

	}
	while (command != "exit");


}
