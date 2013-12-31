// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "Employee.h"
#include "Client.h"
#include "Account.h"
#include "Password.h"
#include <string>
#include <iostream>
#include <map>
#include<fstream>
#include <stdlib.h> 
using namespace std;

// constructor
Employee::Employee(string id, string pass, string r)
{
	userID = id;
	password = pass;
	role = r;
	p = Password();
}

// sets the maps for the employee
void Employee::setInfo(map<string, Employee> employ, map<string, Client> client, map<int, Account> account)
{
	employees = employ;
	clients = client;
	accounts = account;
}

// creates a new employee and adds it to the map
void Employee::addStaff(string id, string pass, string role) 
{
	if (!id.empty() && !pass.empty())
	{
		Employee k = Employee(id, pass, role);
		employees.insert(make_pair(id, k));
		cout << "A new branch staff member is added!\n";
		cout << "User Name: " << id << "\tRole: " << role << "\n";
	}
	else
		cout << "Warning - New branch staff member not created due to null value!\n";
}

// deletes the specified employee
void Employee::delStaff(string id) 
{
	std::map<string, Employee>::iterator e;
	e = employees.find(id);
	
	if (e == employees.end())
		cout << "Warning - User " << id << " is not in the system. No user is deleted!\n";
	else
	{
		employees.erase(id);
		cout << "User " << id << " was deleted!\n";
	}
}

// displays all employees in the map
void Employee::displayBranch() 
{	
	std::map<string, Employee>::iterator it;
	int k = 1;
	cout << "There are " << employees.size() << " users in the system.\n";
	for(it = employees.begin(); it!=employees.end(); ++it)
	{
		if (it->second.getRole() == "System Administrator")
		{
			cout << k << ". User Name: " << it->second.getID() << "\tRole: " << it->second.getRole() << "\n";
			k++;
		}
	}
	for(it = employees.begin(); it!=employees.end(); ++it)
	{
		if (it->second.getRole() == "Branch Staff")
		{
			cout << k << ". User Name: " << it->second.getID() << "\tRole: " << it->second.getRole() << "\n";
			k++;
		}
	}
}

// creates a new client and adds it to the map
void Employee::addClient(string name, string ss, string address, string employer, int income) 
{
	
	Client k = Client(name, ss, address, employer, income);
	clients.insert(make_pair(name, k));
	
}

// creates a new account and adds it to the map
void Employee::addAcct(string name, int acctNum, string acctType, int acctBal) 
{
	if (!acctType.empty())
	{
		Account k = Account(name, acctNum, acctType, acctBal);
		accounts.insert(make_pair(acctNum, k));
		cout << "A new Account was created for " << name << "!\n";
	}
	else
		cout << "Error - Failed to create new account due to null value!\n";
}

// prints the specified clients information, then allows it to be edited
bool Employee::editClient(string name) 
{
	bool k = true;
	bool t = true;
	string holder;
	string hAdd;
	string hSS;
	string hEmpl;
	int hInc;
	string in;
	std::map<string, Client>::iterator c;
	c = clients.find(name);
	
	if (c != clients.end())
	{
		k = false;
		cout << "Display " << name << "'s information:\n";
		cout << "Address: " << c->second.getAddress() << "\n";
		cout << "Social security number: " << c->second.getSS() << "\n";
		cout << "Employer: " << c->second.getEmployer() << "\n";
		cout << "Annual income: " << c->second.getIncome() << "\n";
		cout << "Client " << name << "'s information will be updated...\n";
		while (t == true)
		{
			cout << "1) Confirm\n";
			cout << "2) Cancel\n";
			cout << "Please choose an option: ";
			getline(cin, in);
			if (in == "1")
			{
				cout << "Address: ";
				getline(cin, hAdd);
				cout << "Social security number: ";
				getline(cin, hSS);
				cout << "Employer: ";
				getline(cin, hEmpl);
				cout << "Annual income: ";
				getline(cin, holder);
				hInc = atoi(holder.c_str());
					if (!hAdd.empty() && !hEmpl.empty() && !hSS.empty())
					{
						c->second.setAddress(hAdd);
						c->second.setSS(hSS);
						c->second.setEmployer(hEmpl);
						c->second.setIncome(hInc);
						cout << "Client " << name << "'s information was updated!\n";
						t = false;
					}
					else
						cout << "Warning - Failed to update client due to null value(s)!\n";
			} 
			else if (in == "2")
			{
				t = false;
				cout << "Process has been Canceled.\n";
			}
			else
				cout << "Invalid entry\n";	
		}
	}
	else
		cout << "Error - The Client is not found in the system!\n";
	return k;
}

// changes the employees pass if it different than the original
bool Employee::changePass(string pass) 
{
	bool k = false;
	if (pass == password)
		cout << "Error - Your new password must be different from the old one!\n";
	else
	{
		k = true;
		cout << "Password changed!\n";
		this->password = pass;
	}
	return k;
}

// gives options to change the account. (withdraw/deposit)
bool Employee::editAcct(int acctNum) 
{
	bool k = true;
	bool t = false;
	string holder;
	string in;
	double n = 0.0;
	std::map<int, Account>::iterator a;
	a = accounts.find(acctNum);
	
	if (a == accounts.end())
		cout << "Error - Account " << acctNum << " is not in the system!\n";
	else
	{
		t = true;
		k = false;
	}
	while(t == true)
	{
		cout << "1) Deposit\n";
		cout << "2) Withdraw\n";
		cout << "3) Cancel\n";
		cout << "Please choose an option: ";
		getline(cin, in);
		if (in == "1")
		{
			cout << "Deposit Amount: ";
			getline(cin, holder);
			n = atoi(holder.c_str());
			a->second.deposit(n);
			cout << "Balance of account " << acctNum << " is: " << a->second.getBalance() << "\n";
		}
		else if (in == "2")
		{
			cout << "Withdraw Amount: ";
			getline(cin, holder);
			n = atoi(holder.c_str());
			a->second.withdraw(n);
			cout << "Balance of account " << acctNum << " is: " << a->second.getBalance() << "\n";
		}
		else if (in == "3")
		{
			t = false;
		}
		else
			cout << "Invalid entry, please reenter!\n";
	}
	return k;
}

// gives optioons for the user to edit clients and accounts
void Employee::client()
{
	bool k = true;
	string in;
	string name;
	string address;
	string social;
	string employer;
	string holder;
	int income;
	int acctNum;
	string type;
	double balance;
	std::map<string, Client>::iterator c;
	cin.clear();
	while (k == true)
	{

		cout << "\n\t===========================================================\n";
		cout << "\t|  Teller Terminal System - Client and Account Management |\n";
		cout << "\t===========================================================\n";
		cout << "1) Add a client\n";
		cout << "2) add an account\n";
		cout << "3) Edit Client Information\n";
		cout << "4) Manage an account\n";
		cout << "5) Save Client and Account Information\n";
		cout << "6) Exit\n";
		cout << "Please choose an option: ";
		getline(cin, in);
		if(in == "1")
		{
			cout << "A new client will be added: \n";
			cout << "Client name: ";
			getline(cin, name);
			cout << "Address: ";
			getline(cin, address);
			cout << "Social security number: ";
			getline(cin, social);
			cout << "Employer: ";
			getline(cin, employer);
			cout << "Annual income: ";
			getline(cin, holder);
			income = atoi(holder.c_str());
			addClient(name, social, address, employer, income);
			cout << "A new Client was created!\n";
			p.paktc();
		}
		else if(in == "2")
		{
			while(k == true)
			{
				cout << "Choose a client: ";
				getline(cin, name);
				c = clients.find(name);
				if(c == clients.end())
				{
					cout << "Error - The client is not in the system!\n";
				}
				else
				{
					cout << "A new account will be created for " << name << " ... \n";
					cout << "Account Number: ";
					getline(cin, holder);
					acctNum = atoi(holder.c_str());
					cout << "Account Type: ";
					getline(cin, type);
					cout << "Balance: ";
					getline(cin, holder);
					balance = atoi(holder.c_str());
					addAcct(name, acctNum, type, balance);
					p.paktc();
					k = false;
				}
			}
			k = true;
		}
		else if(in == "3")
		{
			while (k == true)
			{
				cout << "Choose a Client: ";
				getline(cin, name);
				k = editClient(name);
			}
			k = true;
			p.paktc();
		}
		else if(in == "4")
		{
			while (k == true)
			{
				cout << "Which account will be managed? ";
				getline(cin, holder);
				acctNum = atoi(holder.c_str());
				k = editAcct(acctNum);
			}
			k = true;
		}
		else if(in == "5")
		{
			saveInfo();
			p.paktc();
		}
		else if(in == "6")
		{
			k = false;
		}
		else
			cout << "Error - Please enter a valid option!\n";
	}
}

// saves the client and account information into .dats
void Employee::saveInfo() 
{
	std::map<int, Account>::iterator a;
	std::map<string, Client>::iterator c;
	
	string acctfile = "account-info.dat";
	string clientfile = "client-info.dat";
	
	ofstream accountFile(acctfile.c_str());
	ofstream clientFile(clientfile.c_str());
	if (accounts.size() > 0)
	{
		for(a = accounts.begin(); a!=accounts.end(); ++a)
		{
			accountFile << a->second.getName() << "\n" <<  a->second.getAcctNum() << "\n" <<  a->second.getType();
			accountFile << "\n" <<  a->second.getBalance() << "\n";
		}
	}
	accountFile.close();
	
	if (clients.size() > 0)
	{
		for(c = clients.begin(); c!=clients.end(); ++c)
		{
			clientFile << c->second.getName() << "\n" << c->second.getSS() << "\n" << c->second.getAddress();
			clientFile << "\n" << c->second.getEmployer() << "\n" << c->second.getIncome() << "\n";
		}
	}
	clientFile.close();
	
	cout << "Client information has been saved in the client-info file; account\n";
	cout << "information has been saved in the account-info file!\n";
}

// returns the role
string Employee::getRole()
{
	string r;
	r = role;
	return r;
}

// returns the userID
string Employee::getID()
{
	string id;
	id = userID;
	return id;
}

// returns the password
string Employee::getPass()
{
	string pass;
	pass = password;
	return pass;
}

// returns the client map
map<string, Client> Employee::getClients()
{
	return this->clients;
}

// returns the employee map
map<string, Employee> Employee::getEmployees()
{
	return this->employees;
}

// returns the account map
map<int, Account> Employee::getAccounts()
{
	return this->accounts;
}