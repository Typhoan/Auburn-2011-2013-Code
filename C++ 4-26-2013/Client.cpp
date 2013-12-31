// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 and jGrasp to compile code.
// Use of the book and cplusplus.com for references.

#include "Client.h"
using namespace std;

// constructor
Client::Client(string id, string ss, string add, string employ, int inc)
{
	name = id;
	address = add;
	employer = employ;
	social = ss;
	income = inc;
}

// sets the address
void Client::setAddress(string ads) 
{
	this->address  = ads;
}

// returns the address
string Client::getAddress()
{
	return this->address;
}

// sets the employer
void Client::setEmployer(string employ) 
{
	this->employer = employ;
}

// return the employer
string Client::getEmployer()
{
	return this->employer;
}

// sets the income
void Client::setIncome(int inc)
{
	this->income = inc;
}

// returns the income
int Client::getIncome()
{
	return this->income;
}

// sets the social security
void Client::setSS(string ss)
{
	this->social = ss;
}

// returns the social security
string Client::getSS()
{
	return this->social;
}

// returns the name
string Client::getName()
{
	return this->name;
}