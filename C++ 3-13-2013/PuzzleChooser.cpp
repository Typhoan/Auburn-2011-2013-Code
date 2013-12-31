// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "PuzzleChooser.h"
#include "Player.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

//constructor
PuzzleChooser::PuzzleChooser(Player* p)
{
	player = p;
}

// returns a boolean based on if they got the correct answer
bool PuzzleChooser::answers(string ans, string choice)
{
	bool correct = false;
	
	if(ans == choice)
	{
		correct = true;
	}else
	{
		correct = false;
	}
	
	return correct;
}

// returns a boolean if the answer is a valid choice
bool PuzzleChooser::valid(string ans)
{
	bool valid = false;
	
	if(ans == "1" || ans == "2" || ans== "3" || ans == "4")
	{
		valid = true;
	}else
	{
		cout << "\nInvalid entry, please enter a valid answer. (1, 2, 3, 4)\n\n";
	}

	return valid;
}


void PuzzleChooser::puzzle1() 
{
	string answer;
	bool k = true;
	cout << "*You hear someone running towards you, you turn and see a fellow grad student*\n";
	cout << "Hey! Can you help me with this math question?\n";
	cout << "5 = 2a, What is the value of a?\n\n";
	cout << "1) 12\n";
	cout << "2) 5.75\n";
	cout << "3) 2.5\n";
	cout << "4) 7\n\n";
	cin >> answer;
	
	while(k)
	{
		if(valid(answer))
		{
			k = false;
			if(answers("3", answer))
			{
				cout << "That's correct, I think you have gotten smarter!\n";
				cout << "You have gained 1 intellect!\n\n";
				player->addIntel(1);
			}else
			{
				cout << "That's incorrect I think you have gotten dumber!\n";
				cout << "You have lost 2 intellect!\n\n";
				player->addIntel(-2);
			}
		}
		else
		{
			cin >> answer;
		}
	}
}

void PuzzleChooser::puzzle2() {
	string answer;
	bool k = true;
	cout << "*You hear someone running towards you, you turn and see a fellow grad student*\n";
	cout << "Hey! Can you help me with this math question?\n";
	cout << "15 = 5a, What is the value of a?\n\n";
	cout << "1) 3\n";
	cout << "2) 6.75\n";
	cout << "3) 1\n";
	cout << "4) 10\n\n";
	cin >> answer;
	
	while(k)
	{
		if(valid(answer))
		{
			k = false;
			if(answers("1", answer))
			{
				cout << "That's correct, I think you have gotten smarter!\n";
				cout << "You have gained 1 intellect!\n\n";
				player->addIntel(1);
			}else
			{
				cout << "That's incorrect I think you have gotten dumber!\n";
				cout << "You have lost 2 intellect!\n\n";
				player->addIntel(-2);
			}
		}
		else
		{
			cin >> answer;
		}
	}
}

void PuzzleChooser::puzzle3() 
{
	string answer;
	bool k = true;
	cout << "And a mysterious old man appears before you! He says, \n";
	cout << "Stop. Who would cross the Hall of Death must answer me this question, \n" ;
	cout << "ere the other side he see.\n";
	cout << "What is your name?\n\n";
	cout << "1) Sir Lancelot\n";
	cout << "2) Sir Robbin\n";
	cout << "3) Galahad\n";
	cout << "4) " << player->getName() << "\n\n";
	cin >> answer;
	while(k)
	{
		if(valid(answer))
		{
			k = false;
			if(answers("4", answer))
			{
				cout << "That's correct! I'll see you again! *He vanishes in a poof of smoke*\n";
				cout << "You gained 1 intellect!\n\n";
				player->addIntel(1);
			}else
			{
				cout << "You feel a force come over you. You feel your memories being destroyed\n";
				cout << "You have lost all your intellect!\n\n";
				player->addIntel(-1*(player->getIntel()));
			}
		}
		else
		{
			cin >> answer;
		}
	}

}

void PuzzleChooser::puzzle4() 
{
	string answer;
	bool k = true;
	cout << "And a mysterious old man appears before you! He says, \n";
	cout << "Stop. Who would cross the Hall of Death must answer me this question, \n" ;
	cout << "ere the other side he see.\n";
	cout << "What is your Quest?\n\n";
	cout << "1) To seek the holy grail!\n";
	cout << "2) To get the end of the hall!\n";
	cout << "3) To go home!\n";
	cout << "4) I dunno that!\n\n";
	cin >> answer;

	while(k)
	{
		if(valid(answer))
		{
			k = false;
			if(answers("2", answer))
			{
				cout << "That's correct! I'll see you again! *He vanishes in a poof of smoke*\n";
				cout << "You found 2 money!\n\n";
				player->addMoney(2);
			}else
			{
				cout << "The old man starts laughing, you feel your wallet missing as he disappears.\n";
				cout << "You have lost all your money!\n\n";
				player->addMoney(-1*(player->getMoney()));
			}
		}
		else
		{
			cin >> answer;
		}
	}

}

void PuzzleChooser::puzzle5() 
{
	string answer;
	bool k = true;
	
	cout << "And a mysterious old man appears before you! He says, \n";
	cout << "Stop. Who would cross the Hall of Death must answer me this question, \n" ;
	cout << "ere the other side he see.\n";
	cout << "What is the wing-speed velocity of an unladen swallow?\n\n";
	cout << "1) African or European?\n";
	cout << "2) 40,000 meters per second\n";
	cout << "3) 100,000 meters per second\n";
	cout << "4) I dunno that!\n\n";
	cin >> answer;
	
	while(k)
	{
		if(valid(answer))
		{
			k = false;
			if(answers("1", answer))
			{
				cout << "The old man responds, \"I dunno...\" The old man then suddenly disappears.\n";
				cout << "You have gained 5 intellect and 3 money!\n\n";
				player->addIntel(5);
				player->addMoney(3);
			}else
			{
				cout << "The old man starts laughing, you suddenly black out.\n";
				cout << "You have lost all your time!\n\n";
				player->subTime(player->getTime());
			}
		}
		else
		{
			cin >> answer;
		}
	}

}

void PuzzleChooser::puzzle6() 
{
	string answer;
	bool k = true;
	cout << "*You hear someone running towards you, you turn and see a fellow grad student*\n";
	cout << "Hey! Can you help me with this math question?\n";
	cout << "f(x) = 2x^2 + x, What is the derivative of f(x)?\n\n";
	cout << "1) 5x\n";
	cout << "2) 4\n";
	cout << "3) x + 3\n";
	cout << "4) 4x +1\n\n";
	cin >> answer;

	while(k)
	{
		if(valid(answer))
		{
			k = false;
			if(answers("4", answer))
			{
				cout << "That's correct, I think you have gotten smarter!\n";
				cout << "You have gained 1 intellect!\n\n";
				player->addIntel(1);
			}else
			{
				cout << "That's incorrect I think you have gotten dumber!\n";
				cout << "You have lost 2 intellect!\n\n";
				player->addIntel(-2);
			}
		}
		else
		{
			cin >> answer;
		}
	}

}

void PuzzleChooser::puzzle7() 
{
	string answer;
	bool k = true;
	
	cout << "*You hear someone running towards you, you turn and see a fellow grad student*\n";
	cout << "Hey! Can you help me with this math question?\n";
	cout << "f(a) = 6a + 2, What is the integral of f(a)?\n\n";
	cout << "1) 6\n";
	cout << "2) 3a^2 + 2a\n";
	cout << "3) 2a\n";
	cout << "4) 6a + 2a\n\n";
	cin >> answer;

	while(k)
	{
		if(valid(answer))
		{
			k = false;
			if(answers("2", answer))
			{
				cout << "That's correct, Here is some cash!\n";
				cout << "You have gained 2 money!\n\n";
				player->addMoney(2);
			}else
			{
				cout << "That's incorrect I think you have gotten dumber!\n";
				cout << "You have lost 5 intellect!\n\n";
				player->addIntel(-5);
			}
		}
		else
		{
			cin >> answer;
		}
	}

}

void PuzzleChooser::puzzle8() 
{
	string answer;
	bool k = true;
	
	cout << "*You hear someone running towards you, you turn and see a fellow grad student*\n";
	cout << "Hey! Can you help me with this programming question?\n";
	cout << "What function is required to run any c++ program?\n\n";
	cout << "1) strings\n";
	cout << "2) cin\n";
	cout << "3) main\n";
	cout << "4) cout\n\n";
	cin >> answer;

	while(k)
	{
		if(valid(answer))
		{
			k = false;
			if(answers("3", answer))
			{
				cout << "That's correct, I think you have gotten smarter!\n";
				cout << "You have gained 2 intellect!\n\n";
				player->addIntel(2);
			}else
			{
				cout << "That's incorrect I think you have gotten dumber!\n";
				cout << "You have lost 7 intellect!\n\n";
				player->addIntel(-7);
			}
		}
		else
		{
			cin >> answer;
		}
	}

}
 // chooses a random puzzle from 8 different puzzles
void PuzzleChooser::generatePuzzle(int num)
{
	if (num == 0)
	{
		puzzle1();
	}
	if (num == 1)
	{
		puzzle2();
	}
	if (num == 2)
	{
		puzzle3();
	}
	if (num == 3)
	{
		puzzle4();
	}
	if (num == 4)
	{
		puzzle5();
	}
	if (num == 5)
	{
		puzzle6();
	}
	if (num == 6)
	{
		puzzle7();
	}
	if (num == 7)
	{
		puzzle8();
	}
}

PuzzleChooser* PuzzleChooser::getPuzzleChooser()
{
	return this;
}

