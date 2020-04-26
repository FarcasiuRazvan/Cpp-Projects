#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printRepositoryMenu();
	static void printShelterMenu();

	void addDogToRepo();
	void deleteDogFromRepo();
	void displayAllDogsRepo();
	void addDogToShelter();
	void updateDogToRepo();
	int deleteDogFromShelter();
	void addAllDogsByBreedToShelter();
	void showDogs();
	void nextDog();
	void showDogsCond();
	void nextDogCond(const std::string& breed, int age);
	void adoptDog();
	void displayUserList();
	void addAllDogsToShelter();
	void saveUserListToFile();
};

