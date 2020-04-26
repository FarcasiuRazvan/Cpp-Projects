#pragma once
#include "dog.h"
#include <vector>

class Repository
{
private:
	std::vector<dog> dogs;
	std::string filename;

public:
	/*
	Constructor with parameters.
	Initializes an object of type repository, by reading data from the given file.
	Throws: FileException - if the file cannot be opened.
	*/
	Repository(const std::string& name);

	//Adds a dog to the repository.
	void addDog(const dog& d);

	//Deletes a dog from the repository.
	void deleteDog(const dog& d);

	//Update a dog from the repository.
	void updateDog(const dog& d);

	//Finds a dog by name and breed.
	dog findByNameAndBreed(const std::string& name, const std::string& breed);

	//Return the given dog's position.
	int findDogPosition(const dog& d);

	//Return the array of dogs.
	std::vector<dog> getDogs() const { return dogs; }

	int getSizeR() const { return dogs.size(); }



public:
	void readFromFile();
	void writeToFile(std::string filename);
};