#ifndef GAMECONTROLLER  
#define GAMECONTROLLER
#include "Encounter.h"
#include "Player.h"
#include "Highscore.h"


class GameController {

private:

	Player* player;
	Highscore* highscores;
	Encounter* encounters;
	bool playing;

public:

	GameController(Player* p, Highscore* h, Encounter* e);
	
	void move();

	void readPapers();

	void viewCharacter();

	void findCash();

	void viewHighscores();

	void quitGame();

	void startGame();
	
	bool play();

};
#endif