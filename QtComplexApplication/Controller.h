#pragma once
#include "Repository.h"
#include "FileShelter.h"
#include "Shelter.h"
#include "DogValidator.h"
#include <vector>
#include <memory>
#include "Undo.h"
#include "Redo.h"

class Controller
{
private:
	Repository repo;
	//FileShelter* user_list;
	Shelter shelter;
	DogValidator validator;
	//std::vector<std::unique_ptr<UndoAction>> undoActions;
	//std::vector<std::unique_ptr<UndoAction>> redoActions;
	std::vector<UndoAction*> undoActions;
	std::vector<UndoAction*> redoActions;
public:
	FileShelter *user_list;
	Controller(const Repository& r, FileShelter* p) : repo(r), user_list(p) {}

	Controller(const Controller& ctrl) = delete;
	void operator=(const Controller& ctrl) = delete;

	Repository getRepo() const { return repo; }
	Shelter getShelter() const { return shelter; }
	std::vector<dog> getAdoptionList() const { return user_list->getUserList(); }
	FileShelter* getUserList() const { return user_list; }

	//Adds a dog with the given data to the dogs repository.
	void addDogToRepository(const std::string& name, const std::string& breed, int age, const std::string& photo);

	//Update a dog from the repository with the given data.
	void updateDogToRepository(const std::string& name, const std::string& breed, int age, const std::string& photo);

	//Deletes a dog from the repository.
	void deleteDogFromRepository(const std::string& name, const std::string& breed);

	//Adds a dog to the shelter.
	void addDogToShelter(const dog& d);

	//Adds all dogs with the same breed to shelter.
	void addAllDogsByBreedToShelter(const std::string& breed);

	//Remove dog from the shelter.
	void deleteDogFromShelter(const dog &d);

	//Start the shelter.
	void startShelter();

	//Move to the next dog.
	void nextDogShelter();

	//Iter throught the shelter.
	void iterDogShelter();

	//Iter throught dogs with a given breed and return 0 if that breed doesn't exist 
	//or there is no dog with the given breed that has its age less than a given age. 
	int iterThroughtBreeds(const std::string& breed, int age);

	//Returns the current showing dog from the shelter.
	dog getCurrentDogShelter();

	//Show current image.
	void showCurrentImage();

	//Adopt a dog from the shelter.
	void adoptDog();

	int isEmptyShelter() { return shelter.isEmpty(); }

	void addAllDogsToShelter();
	
	int getSizeRepo() { return repo.getSizeR(); }

	int getSizeShelter() { return shelter.getSizeS(); }

	void saveUserList();

	void displayUserList();

	void undo();

	void redo();
};