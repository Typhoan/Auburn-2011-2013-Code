// Ian McPherson
// irm0003@auburn.edu
// Used Cygwin on a Windows7 to compile code. Also used jGrasp.
// Use of the book and cplusplus.com for references.

#include "Menu.h"
#include "Employee.h"
#include "Client.h"
#include "Account.h"
#include "Password.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include<fstream>
using namespace std;

// constructor
Menu::Menu()
{
	bool k = true;
	
	string in;
	p = Password();
	
	while (k == true)
	{
		populateUsers();
		cout << "\n\t===========================================================\n";
		cout << "\t|       Welcome to the Auburn Branch of Tiger Bank!       |\n";
		cout << "\t===========================================================\n";
		cout << "1) Login\n";
		cout << "2) Quit\n";
		cout << "\tPlease choose an option: ";
		getline(cin, in);
		
		if (in == "1")
		{
			login();
		}
		else if (in == "2")
		{
			k = false;
		}
		else 
		{
			cout << "Error - Please enter a valid option!\n";
		}
		saveData();
	}
}

// login menu
void Menu::login() 
{
	bool k = true;
	int i = 0;
	string pword = "";
	string id;
	std::map<string, Employee>::iterator e;
	
	cout << "\n\t===========================================================\n";
	cout << "\t|        Login to Access the Teller Terminal System       |\n";
	cout << "\t===========================================================\n";

	while (k == true)
	{
		cout << "User Name: ";
		getline(cin, id);
		cout << "Password: ";
		getline(cin, pword);
		
		e = employees.find(id);
		if(e != employees.end() && e->second.getPass() == pword)
		{
			e->second.setInfo(employees, clients, accounts);
			
			if(e->second.getRole() == "System Administrator")
			{
				admin(e);
				k = false;
			}
			else
			{
				k = false;
				staff(e);
			}
		}
		else
		{
			id = "";
			pword = "";
			cout << "The user name or password is incorrect. Try again!\n";
		}
	}

	
}

// admin menu
void Menu::admin(std::map<string, Employee>::iterator i) 
{
	bool k = true;
	bool pchanged = false;
	string in;
	string pword;
	string name;
	string role;
	std::map<string, Employee>::iterator e = i;
	while (k == true)
	{
		cout << "\n\t===========================================================\n";
		cout << "\t|      Teller Terminal System - System Administration     |\n";
		cout << "\t===========================================================\n";
		cout << "1) Client and Account Management\n";
		cout << "2) Add a branch staff member\n";
		cout << "3) Delete a branch staff member\n";
		cout << "4) Display branch staff\n";
		cout << "5) Change Password\n";
		cout << "6) Exit\n";
		cout << "Please choose an option: ";
		getline(cin, in);
		
		if (in == "1")
		{
			client(e);
		}
		else if(in == "2")
		{
			while (k == true)
			{
				cout << "User Name: ";
				getline(cin, name);
				cout << "Password: ";
				getline(cin, pword);
				
				while (k == true)
				{
					cout << "Role (1 - Administrator; 2 - Branch Staff): ";
					getline(cin, in);
					if ( in == "1")
					{
						role = "System Administrator";
						k = false;
					}
					else if (in == "2")
					{
						role = "Branch Staff";
						k = false;
					}
					else
						cout << "Error - Please enter a valid option!\n";
				}
				k = true;
				
				while (k == true)
				{
					cout << "1) Confirm\n";
					cout << "2) Cancel\n";
					cout << "Please choose an option: ";
					getline(cin, in);
					if(in == "1")
					{
						e->second.addStaff(name, pword, role);
						k = false;
					}
					else if(in == "2")
					{
						k = false;
					}
					else
						cout << "Error - Please enter a valid option!\n";
				}
			}
			k = true;
			p.paktc();
		}
		else if(in == "3")
		{
			while (k == true)
			{
				cout << "Delete a user - User name: ";
				getline(cin, name);
				
				cout << "1) Confirm\n";
				cout << "2) Cancel\n";
				
				getline(cin, in);
				if(in == "1")
				{
					e->second.delStaff(name);
					k = false;
				}
				else if(in == "2")
				{
					k = false;
				}
				else
					cout << "Error - Please enter a valid option!\n";
			}
			in = "3";
			k = true;
		}	
		else if(in == "4")
		{
			e->second.displayBranch();
		}
		else if(in == "5")
		{
			while(!pchanged)
			{
				cout << "New Password: ";
				getline(cin, pword);
				pchanged = e->second.changePass(pword);
			}
		}
		else if(in == "6")
		{
			k = false;
			employees = e->second.getEmployees();
			clients = e->second.getClients();
			accounts = e->second.getAccounts();
		}
		else
			cout << "Error - Please enter a valid option!\n";
		
	}
}

// Branch staff menu
void Menu::staff(std::map<string, Employee>::iterator i) 
{
	bool k = true;
	bool pchanged = false;
	string in;
	string pword;
	std::map<string, Employee>::iterator e = i;
	while (k == true)
	{
		cout << "\n\t===========================================================\n";
		cout << "\t|          Teller Terminal System - Branch Staff          |\n";
		cout << "\t===========================================================\n";
		cout << "1) Client and Account Management\n";
		cout << "2) Change Password\n";
		cout << "3) Exit\n";
		cout << "Please choose an option: ";
		getline(cin, in);
		
		if (in == "1")
		{
			client(e);
		}
		else if(in == "2")
		{
			while(!pchanged)
			{
				cout << "New Password: ";
				getline(cin, pword);
				pchanged = e->second.changePass(pword);
			}
		}
		else if(in == "3")
		{
			k = false;
			employees = e->second.getEmployees();
			clients = e->second.getClients();
			accounts = e->second.getAccounts();
		}
		else
			cout << "Error - Please enter a valid option!\n";	
	}
}

// client options menu
void Menu::client(std::map<string, Employee>::iterator i)
{
	std::map<string, Employee>::iterator e = i;
	e->second.client();	
}

// generates maps from the .dats
void Menu::populateUsers() 
{
	string name;
	string pass;
	string role;
	string ss;
	string type;
	string employer;
	string address;
	int income;
	int acctNum;
	double balance;
	string employfile = "employees.dat";
	string acctfile = "account-info.dat";
	string clientfile = "client-info.dat";
	
	std::map<string, Employee>::iterator it;
	
	ifstream clientFile;
	ifstream employFile;
	ifstream acctFile;
	
	employFile.open(employfile.c_str());
	acctFile.open(acctfile.c_str());
	clientFile.open(clientfile.c_str());
	
	if(!clientFile)
	{	
		ofstream outClientFile(clientfile.c_str());
		outClientFile.close();
	}
	else
	{
		while(!clientFile.eof())
		{
			string s;
			
			getline(clientFile, name);
			getline(clientFile, ss);
			getline(clientFile, address);
			getline(clientFile, employer);
			getline(clientFile, s);
			
			istringstream tmp(s);
			tmp >> income;
			
			Client c = Client(name, ss, address, employer, income);
			clients.insert(make_pair(name, c));
		}
	}
	clientFile.close();

	
	if(!acctFile)
	{	
		ofstream outAcctFile(acctfile.c_str());
		outAcctFile.close();
	}
	else
	{
		while(!acctFile.eof())
		{
			string s;
			
			getline(acctFile, name);
			getline(acctFile, s);
			istringstream tmp(s);
			tmp >> acctNum;
			
			getline(acctFile, type);
			getline(acctFile, s);
			
			istringstream tmp2(s);
			tmp2 >> balance;
			
			Account a = Account(name, acctNum, type, balance);
			accounts.insert(make_pair(acctNum, a));
		}
	}
	acctFile.close();
	
	if(!employFile)
	{	
		Employee k = Employee("admin", "0000", "System Administrator");
		employees.insert(make_pair("admin", k));
		ofstream outEmployFile(employfile.c_str());
		outEmployFile << "admin 0000 Administrator\n";
		outEmployFile.close();
	}
	else
	{
		while(!employFile.eof())
		{
			employFile >> name;
			employFile >> pass;
			employFile >> role;
			
			if (role == "Administrator")
			{
				Employee k = Employee(name, pass, "System Administrator");
				employees.insert(make_pair(name, k));
			}
			else
			{
				Employee k = Employee(name, pass, "Branch Staff");
				employees.insert(make_pair(name, k));
			}
		}
	}
	employFile.close();	
}

// saves the employee data
void Menu::saveData()
{
	std::map<string, Employee>::iterator e;

	string employfile = "employees.dat";
	
	ofstream employmentFile(employfile.c_str());
	string role;
		
	for(e = employees.begin(); e!=employees.end(); ++e)
	{
			if (e->second.getRole() == "System Administrator")
				role = "Administrator";
			else
				role = "Staff";
				
			employmentFile << e->second.getID() << " " << e->second.getPass() << " " << role << "\n";
	}
	employmentFile.close();	
}

// runs the program
int main()
{
	Menu m = Menu();
	
	return 0;
}