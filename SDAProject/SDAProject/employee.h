#pragma once
#include <string>

class employee
{
private:
	std::string name;
	int tn;
public:
	employee() {};
	employee(std::string n, int t) { this->name = n; this->tn = t; };
	
	std::string getName() { return this->name; };
	int getTelNo() { return this->tn; };


	void setName(std::string name) { this->name = name; }
	void setTelNo(int n) { this->tn = n; }
};