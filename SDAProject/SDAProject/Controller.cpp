#include "Controller.h"



void Controller::add(std::string name, int tn)
{
	employee e(name,tn);
	//validari

	this->set.add(e);
}

void Controller::remove(std::string name, int tn)
{
	employee e(name, tn);
	//validari
	this->set.remove(e);
}

bool Controller::check(std::string name, int tn)
{
	employee e(name, tn);
	return this->set.find(e);
}

void Controller::destroy()
{
}
