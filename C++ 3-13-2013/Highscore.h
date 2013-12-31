#ifndef HIGHSCORE  
#define HIGHSCORE
#include <string>

class Highscore {

private:
	std::string file;
	int highscores[5];
	std::string nameHighscores[5];

public:
	Highscore();

	void recordHighscores();

	void printHighscores();

	void addHighscore(int int_score, std::string String_name);
	
	Highscore* getHighscore();
};
#endif