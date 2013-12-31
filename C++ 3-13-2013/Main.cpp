// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include <iostream>
#include <string>
#include<fstream>

//class definitions 
#include "Encounter.h"
#include "GameController.h"
#include "Highscore.h"
#include "Player.h"
#include "PuzzleChooser.h"

using namespace std;

int main()
{	
	string name;
	bool started = true;
	string choice;
	
	cout << "\tWhat is your name?";
	cin >> name;
	
	while(name == "--")
	{
		cout << "Invalid name, please reenter.\n";
		cin >> name;
	}
	
	cout << "\n\t\t===========================================================\n";
	cout << "\t\t|                     Welcome, " << name << "!                        |\n";
	cout << "\t\t===========================================================\n\n";
	
	Highscore h = Highscore();
	
	while (started)
	{
		cout << "\t1) Start a New Game of Shelby Center and Dragons!\n";
		cout << "\t2) View top 5 High Scores\n";
		cout << "\t3) Quit\n\n";
		
		cout << "\t\tPlease choose an option: ";
		cin >> choice;
		
		cout << "\n";
		
		if (choice == "3")
		{
			cout << "\tThanks for playing!";
			started = false;
		}else if (choice == "2")
		{
			h.printHighscores();
		}else if(choice == "1")
		{
			cout << "Entering the Game...\n\n";
			Player p = Player(name);
			PuzzleChooser pc = PuzzleChooser(p.getPlayer());
			Encounter e = Encounter(p.getPlayer(), pc.getPuzzleChooser());
			GameController gc = GameController(p.getPlayer(), h.getHighscore(), e.getEncounter());
			gc.startGame();
			
			cout << p.generateStats();
			
			while(gc.play())
			{
				cout << "you are " << p.getPosition() << " steps from the goal. Time Left: " << p.getTime() << ".\n\n";
				cout << "\t\t1) Move forward (takes time, could be risky...)\n";
				cout << "\t\t2) Read technical papers (boost intelligence, takes time)\n";
				cout << "\t\t3) Search for loose change (boost money, takes time)\n";
				cout << "\t\t4) View character\n";
				cout << "\t\t5) Quit the game\n\n\n";
				
				cout << "\tPlease choose an action: ";
				cin >> choice;
				cout << "\n\n";
				
				if(choice == "1")
				{
					gc.move();
				} else if(choice == "2")
				{
					gc.readPapers();
				} else if(choice == "3")
				{
					gc.findCash();
				} else if(choice == "4")
				{ 
					gc.viewCharacter();
				} else if(choice == "5")
				{
					gc.quitGame();
				} else
				{
					cout << "Please enter a valid input. (1, 2, 3, 4, 5)\n\n";
				}
			}	
		}
		else
		{
			cout << "Please enter a valid input. (1, 2, 3)\n\n";
		}
	}
	
	
	
   return 0;
}
