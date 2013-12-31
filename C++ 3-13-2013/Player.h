#ifndef PLAYER  
#define PLAYER
#include <string>
class Player 
{

private:
	std::string name;
	int intel;
	int money;
	int position;
	int timeLeft;

public:
	Player(std::string Name);

	int getIntel();
	
	int getTime();
	
	int getMoney();

	int calculateScore();
	
	int getPosition();

	std::string getName();

	std::string generateStats();

	void moveForward();

	void addIntel(int num);
	
	void subTime(int time);
	
	void addMoney(int num);
	
	Player* getPlayer();

};
#endif