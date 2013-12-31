// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "GameController.h"
#include "Player.h"
#include "Encounter.h"
#include "Highscore.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

//Constructor
GameController::GameController(Player* p, Highscore* h, Encounter* e)
{
	player = p;
	encounters = e;
	playing = false;
	highscores = h;
}
// calls enounters chooseEncounter function
void GameController::move() 
{
	encounters->chooseEncounter();
}

// adds intellect and subtracts some time.
void GameController::readPapers() 
{
	srand((unsigned)time(NULL));
	int i = rand() % 4 + 2;
	cout << "You read through some technical papers. You gain \n";
	cout << i << " intelligence, but lost 2 units of time.\n\n";
	player->addIntel(i);
	player->subTime(2);
}

// outputs the character stats
void GameController::viewCharacter() 
{
	cout << player->generateStats();
}

// adds some cash and subtracts some time
void GameController::findCash() 
{
	srand((unsigned)time(NULL));
	int m = rand() % 4 + 2;
	cout << "You dig into your pockets and find some Money. You gain \n";
	cout << m << " units of money, but lost 2 units of time.\n\n";
	player->addMoney(m);
	player->subTime(2);
}

// outputs the highscores
void GameController::viewHighscores() 
{
	highscores->printHighscores();
}

// ends the current game
void GameController::quitGame() 
{
	playing = false;
	cout << "You have quit! Good luck next time!\n\n";
}

// starts a new game
void GameController::startGame() 
{
	playing = true;
}

// tests to see if the player lost
bool GameController::play()
{
	if(player->getIntel() <= 0)
	{
		playing = false;
		cout << "Your intelligence has fallen to 0! You have failed out!\n";
		cout << "Final score: " << player->calculateScore() << "\n\n";
		highscores->addHighscore(player->calculateScore(), player->getName());
		highscores->recordHighscores();
	}
	if(player->getMoney() <= 0)
	{
		playing = false;
		cout << "Your money has fallen to 0! You have starved to death!\n";
		cout << "Final score: " << player->calculateScore() << "\n\n";
		highscores->addHighscore(player->calculateScore(), player->getName());
		highscores->recordHighscores();
	}
	if(player->getTime() <= 0)
	{
		playing = false;
		cout << "Your time has fallen to 0! You have missed all your classes!\n";
		cout << "Final score: " << player->calculateScore() << "\n\n";
		highscores->addHighscore(player->calculateScore(), player->getName());
		highscores->recordHighscores();
	}
	if(player->getPosition() <= 0)
	{
		playing = false;
		cout << "You have reached the end of the Hall! You Win!\n";
		cout << "Final score: " << player->calculateScore() << "\n\n";
		highscores->addHighscore(player->calculateScore(), player->getName());
		highscores->recordHighscores();
	}
	return playing;
}

