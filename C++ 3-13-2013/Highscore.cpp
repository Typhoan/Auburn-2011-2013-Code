// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "Highscore.h"
#include<iostream>
#include<fstream>
using namespace std;

//constructor
Highscore::Highscore() 
{
	file = "Highscores.dat";
	ifstream inFile;
	inFile.open(file.c_str());
	
	
	if(!inFile)
	{	
		ofstream outFile(file.c_str());
		for(int i = 0; i < 5; i++)
		{
			nameHighscores[i] = "--";
			highscores[i] = 0;
			outFile << nameHighscores[i] << " " << highscores[i] << "\n";
		} 
		outFile.close();
	}
	else
	{
		int k = 0;
		while(k < 5)
		{
			inFile >> nameHighscores[k];
			inFile >> highscores[k];
			k++;
		}
	}
	inFile.close();		
}

// outputs a .dat file containing the high scores
void Highscore::recordHighscores() 
{
	ofstream outFile(file.c_str());
	for(int i = 0; i < 5; i++)
	{
		outFile << nameHighscores[i] << " " << highscores[i] << "\n";
	}
	outFile.close();

}

// outputs the high scores
void Highscore::printHighscores() 
{
	cout << "\tThe top 5 High Scores are:\n\n";
	for(int i = 0; i < 5; i++)
	{
		if (nameHighscores[i] != "--")
		{
			cout << "\t" << nameHighscores[i] << " " << highscores[i] << "\n";
		}
	}
	cout << "\t-no more scores to show-\n\n";
}	

// Adds and sorts the new high score
void Highscore::addHighscore(int int_score, string string_name) 
{
	int i = 0;
	int sHolder1 = 0;
	int sHolder2 = 0;
	string nHolder1 = "";
	string nHolder2 = "";
	
	while (int_score < highscores[i] && i < 5)
	{
		i++;
	}
	
	if (i < 5)
	{
		sHolder1 = highscores[i];
		nHolder1 = nameHighscores[i];
		highscores[i] = int_score;
		nameHighscores[i] = string_name;
		i++;
	}
	
	while (i < 5)
	{
		sHolder2 = highscores[i];
		nHolder2 = nameHighscores[i];
		highscores[i] = sHolder1;
		nameHighscores[i] = nHolder1;
		sHolder1 = sHolder2;
		nHolder1 = nHolder2;
		i++;
	} 
}

// returns a pointer of this class
Highscore* Highscore::getHighscore()
{
	return this;
}