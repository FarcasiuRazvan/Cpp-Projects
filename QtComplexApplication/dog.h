#pragma once
#include <iostream>

class dog
{
private:
	std::string name;
	std::string breed;
	int age;
	std::string photo;
public:
	//default constructor for a dog
	dog();

	//contructor with parameters
	dog(const std::string& name, const std::string& breed, const int age, const std::string& photo);

	std::string getName() const { return name; }
	std::string getBreed() const { return breed; }
	int getAge() const { return age; }
	std::string getPhoto() const { return photo; }

	//Show the image of the current dog: the page corresponding to the source link is opened in a browser.
	void image();

	//Return 0 or 1 if the statement == between dog d1 and dog d2 is true or false.
	int operator==(const dog& d2);

	friend std::istream& operator>>(std::istream& is, dog& s);
	friend std::ostream& operator<<(std::ostream& os, const dog& s);
};