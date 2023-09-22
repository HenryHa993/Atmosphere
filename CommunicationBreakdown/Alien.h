#pragma once

#include <iostream>


class Alien
{
public:
	Alien(std::string description);
	void Death();
	bool isAlive();
	bool moved;
;
private:
	bool isAlive_; // Alive status
	std::string description_; // Alien description
};