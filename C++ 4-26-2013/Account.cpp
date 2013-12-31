// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "Account.h"
#include <string>
using namespace std;

// constructor
Account::Account(string id, int accNumber, string type, int bal)
{
	name = id;
	accNum = accNumber;
	accType = type;
	balance = bal;
}

// Adds an int to the balance
void Account::deposit(int num) 
{
	balance += num;
}

// Subtracts an int from the balance
void Account::withdraw(int num) 
{
	balance -= num;
}

// return the account number
int Account::getAcctNum()
{
	return this->accNum;
}

// return the name
string Account::getName()
{
	return this->name;
}

// returns the balance
int Account::getBalance()
{
	return this->balance;
}

// returns the type
string Account::getType()
{
	return this->accType;
}
