#ifndef MENU
#define MENU
#include "Client.h"
#include "Account.h"
#include "Employee.h"
#include "Password.h"
#include <string>
#include <iostream>
#include <map>
#include<fstream>
class Menu {

private:
	std::map<std::string, Employee> employees;
	std::map<std::string, Client> clients;
	std::map<int, Account> accounts;
	Password p;

public:
	Menu(void);
	
	void login();

	void admin(std::map<std::string, Employee>::iterator i);

	void staff(std::map<std::string, Employee>::iterator i);
	
	void client(std::map<std::string, Employee>::iterator i);

	void populateUsers();
	
	void saveData();
};
#endif