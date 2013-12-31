#ifndef ENCOUNTER 
#define ENCOUNTER
#include "PuzzleChooser.h"
#include "Player.h"

class Encounter {

private:
	PuzzleChooser* puzzles;
	Player* player;

public:
	Encounter(Player* p, PuzzleChooser* pc);

	void chooseEncounter();

	void puzzle();

	void teacher();

	void student();

	void gradePapers();

	void gruntWork();

	void nothing();
	
	Encounter* getEncounter();
};
#endif