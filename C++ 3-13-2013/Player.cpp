// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "Player.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// constructor
Player::Player(std::string Name) : name(Name)
{
	srand((unsigned)time(NULL));
	intel = rand() % 18 + 8;
	money = rand() % 18 + 8;
	timeLeft = rand() % 18 + 8;
	position = 20;
}

// returns position
int Player::getPosition()
{
	return position;
}

// returns time
int Player::getTime()
{
	return timeLeft;
}

// returns intellect
int Player::getIntel()
{
	return intel;
}

// returns money
int Player::getMoney()
{
	return money;
}

// returns your score after calculating it from the players money, intellect, time left, and position
int Player::calculateScore() 
{
	int score;
	score = ((money * 2) + (intel * 3) + (timeLeft * 10)) - (position * 5);
	return score;
}

//returns name
string Player::getName() 
{
	return this->name;
}

// outputs the players stats
string Player::generateStats() 
{	
	string i = static_cast<ostringstream*>( &(ostringstream() << intel) )->str();
	string m = static_cast<ostringstream*>( &(ostringstream() << money) )->str();
	string t = static_cast<ostringstream*>( &(ostringstream() << timeLeft) )->str();
	
	string report;
	
	report = "You have:\n\n";
	report += "Intelligence: " + i;
	report += "\nTime: " + t;
	report += "\nMoney: " + m + "\n\n";
	return report;
	
}

// adds a number to the players intellect, can be used to add or subtract
void Player::addIntel(int num) 
{
	intel = intel + num;
}

// adds a number to the players money, can be used to add or subtract
void Player::addMoney(int num) 
{
	money = money + num;
}

// subtracts one from the players position
void Player::moveForward() 
{
	this->position = position - 1;
}

// subtracts a number from the remaining time
void Player::subTime(int time)
{
	timeLeft = timeLeft - time;
}

// returns a point of this class
Player* Player::getPlayer()
{
	return this;
}

