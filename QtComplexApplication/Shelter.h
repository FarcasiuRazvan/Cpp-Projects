#pragma once
#include <vector>
#include "dog.h"

class Shelter
{
protected:
	std::vector<dog> dogs;
	int current;
public:
	Shelter();

	//Adds a dog into the shelter.
	void add(const dog& d);

	std::vector<dog> getDogs() { return dogs; }

	//Update a dog from the shelter.
	void updateDog(const dog& d);

	//Returns the dog that is currently shown.
	dog getCurrentDog();

	//Returns the size of the shelter.
	int getSizeS() { return dogs.size(); }

	//Show the first dog.
	void start();

	//Show the next dog from the shelter.
	void next();

	//Checks if the shelter is empty.
	bool isEmpty();

	//Remove a dog from the shelter.
	void remove(const dog& d);

	//Finds the position of a given dog.
	int findDogPosition(const dog& d);

	//Shows current dog's image.
	void getCurrentImage();

	//Iterate throught the shelter.
	void iter();

	virtual ~Shelter() {}
};


