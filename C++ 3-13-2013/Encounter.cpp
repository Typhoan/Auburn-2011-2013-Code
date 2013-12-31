// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "Encounter.h"
#include "Player.h"
#include "PuzzleChooser.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

// constructor
Encounter::Encounter(Player* p, PuzzleChooser* pc) 
{
	player = p;
	puzzles = pc;
}

// calls a puzzle
void Encounter::puzzle() 
{
	cout << "You take a step forward and... \n\n";
	player->moveForward();
	srand((unsigned)time(NULL));
	int k = rand() % 8;
	puzzles->generatePuzzle(k);
	
}

// sometimes adds intellect and always makes you lose some time
void Encounter::teacher() 
{
	cout << "As you take a step, you hear your professor call ";
	cout << "out your name. \nYou stop and he begins to talk to you. \n";
	cout << "After what feels like an eternity he stops talking ";
	cout << "and walks away. \n";
	
	srand((unsigned)time(NULL));
	int k = rand() % 3 + 1;
	int t = rand() % 2 + 1;
	int i = rand() % 3 + 1;
	
	if(k == 1)
	{
		cout << "You lost " << t << " units of time, but you gained " << i << " units of intelligence.\n\n";
		player->addIntel(i);
	}else
	{
		cout << "You lost " << t << " units of time.\n\n";
	}
	player->subTime(t);
	player->moveForward();
}

// you always lose time
void Encounter::student() 
{
	srand((unsigned)time(NULL));
	int t = rand() % 2 + 1;
	cout << "You take a step and...\n\n";
	cout << "A fellow grad stutdent starts talking to you!\n";
	cout << "You lost " << t << " units of time!\n\n";
	player->subTime(t);
	player->moveForward();
}

// you lose some time and gain some money
void Encounter::gradePapers() 
{
	srand((unsigned)time(NULL));
	int t = rand() % 2 + 1;
	int m = rand() % 3 + 1;
	cout << "You take a step and...\n\n";
	cout << "You find some papers to grade!\n";
	cout << "You lost " << t << " units of time, but gained " << m << " units of money!\n\n";
	player->subTime(t);
	player->addMoney(m);
	player->moveForward();
}

// you lose time and some intellect
void Encounter::gruntWork() 
{
	srand((unsigned)time(NULL));
	int t = rand() % 2 + 1;
	int i = rand() % 3 + 1;
	cout << "You take a step and...\n\n";
	cout << "You find grunt work!\n";
	cout << "You lost " << t << " units of time and lost " << i << " units of intelligence!\n\n";
	player->subTime(t);
	player->addIntel(i);
	player->moveForward();
}

// you just move forward
void Encounter::nothing() 
{
	cout << "You take a step forward.\n\n";
	cout << "You spent 1 unit of time.\n\n";
	player->moveForward();
	player->subTime(1);
}

// decides what enounter the player will get
void Encounter::chooseEncounter() 
{
	srand((unsigned)time(NULL));
	int i = rand() % 100 + 1;
	
	if(i <= 30)
	{
		nothing();
	}
	
	if(i > 30 && i <= 55)
	{
		puzzle();
	}
	
	if(i > 55 && i <= 65)
	{
		teacher();
	}
	
	if(i > 65 && i <= 75)
	{
		student();
	}
	
	if(i > 75 && i <= 90)
	{
		gruntWork();
	}
	
	if(i > 90)
	{
		gradePapers();
	}
}

// returns a pointer of this class
Encounter* Encounter::getEncounter()
{
	return this;
}