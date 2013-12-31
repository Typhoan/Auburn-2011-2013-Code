#ifndef ACCOUNT
#define ACCOUNT
#include <string>
class Account {

private:
	std::string name;
	int accNum;
	std::string accType;
	int balance;

public:
	Account(std::string id, int accNumber, std::string type, int bal);
	
	void deposit(int num);
	
	void withdraw(int num);
	
	int getAcctNum();
	
	std::string getName();
	
	int getBalance();
	
	std::string getType();
};
#endif