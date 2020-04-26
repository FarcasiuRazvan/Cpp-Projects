#pragma once
#include "set.h"

class Controller
{
private:
	Set &set;
public:
	Controller(Set &set) : set(set) {};

	void add(std::string name,int tn);
	void remove(std::string name,int tn);
	bool check(std::string name,int tn);
	void destroy();

	Set* getSet() { return &this->set; }

};