#ifndef CLIENT
#define CLIENT
#include <string>
class Client {

private:
	std::string name;
	std::string address;
	std::string employer;
	std::string social;
	int income;

public:
	Client(std::string id, std::string ss, std::string add, std::string employ, int inc);
	
	void setAddress(std::string add);
	
	std::string getAddress();
	
	void setSS(std::string ss);
	
	std::string getSS();
	
	void setIncome(int inc);
	
	int getIncome();

	void setEmployer(std::string employ);
	
	std::string getEmployer();
	
	std::string getName();
};
#endif