#include "dog.h"

#include <Windows.h>

#include <shellapi.h>
#include "Utils.h"

#include <iostream>

#include <vector>

using namespace std;

dog::dog() : name(""), breed(""), age(), photo("") {}

dog::dog(const std::string& name, const std::string& breed, const int age, const std::string& photo)
{
	this->name = name;
	this->breed = breed;
	this->age = age;
	this->photo = photo;
}

void dog::image()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}

int dog::operator==(const dog& d2)
{
	if (this->name == d2.getName() && this->breed == d2.getBreed()) return 1;
	else return 0;
}

istream & operator>>(istream &is, dog &s)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4) // make sure all the dog data was valid
		return is;

	s.name = tokens[0];
	s.breed = tokens[1];
	s.age = stod(tokens[2]);
	s.photo = tokens[3];

	return is;

}

ostream & operator<<(ostream & os, const dog & s)
{
	os << s.name << "," << s.breed << "," << s.age << "," << s.photo << "\n";
	return os;
}

