// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "Password.h"
#include "Employee.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
using namespace std;

// constructor
Password::Password()
{
	
}

// makes the user press any button to continue
void Password::paktc() 
{
	int ch = -1;
	cout << "Press any key to continue...\n";
	while(ch == -1)
	{
		ch = getch();
	}
}

// returns an int based on user input
int Password::getch (void) 
{

  int ch;
  struct termios oldt, newt;
  
  tcgetattr ( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );
  
  return ch;
} 


