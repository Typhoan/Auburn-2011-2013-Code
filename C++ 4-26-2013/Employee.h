#ifndef EMPLOYEE
#define EMPLOYEE
#include "Client.h"
#include "Account.h"
#include "Password.h"
#include <string>
#include <iostream>
#include <map>
class Employee {

private:
	std::string password;
	std::string userID;
	std::string role;
	std::map<std::string, Employee> employees;
	std::map<std::string, Client> clients;
	std::map<int, Account> accounts;
	Password p;
	

public:
	Employee(std::string id, std::string pass, std::string role);
	
	void setInfo(std::map<std::string, Employee> employ, std::map<std::string, Client> client, std::map<int, Account> account);

	void addStaff(std::string id, std::string pass, std::string role);

	void delStaff(std::string id);

	void displayBranch();
	
	void addClient(std::string name, std::string ss, std::string address, std::string employer, int income);

	void addAcct(std::string name, int acctNum, std::string acctType, int acctBal);

	bool editClient(std::string name);

	bool changePass(std::string pass);

	bool editAcct(int acctNum);

	void saveInfo();
	
	void client();
	
	std::map<std::string, Client> getClients();
	
	std::map<std::string, Employee> getEmployees();
	
	std::map<int, Account> getAccounts();
	
	std::string getPass();
	
	std::string getID();
	
	std::string getRole();
};
#endif