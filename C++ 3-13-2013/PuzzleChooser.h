#ifndef PUZZLECHOOSER  
#define PUZZLECHOOSER
#include "Player.h"
#include <string>

class PuzzleChooser {

private:

	Player* player;

public:
	PuzzleChooser(Player* p);
	
	bool answers(std::string ans, std::string choice);
	
	bool valid(std::string ans);

	void puzzle1();

	void puzzle2();

	void puzzle3();

	void puzzle4();

	void puzzle5();

	void puzzle6();

	void puzzle7();

	void puzzle8();

	void generatePuzzle(int num);
	
	PuzzleChooser* getPuzzleChooser();
};
#endif