#include "Controller.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include "RepositoryExceptions.h"

using namespace std;
//Adds a dog with the given data to the dogs repository.
void Controller::addDogToRepository(const std::string& name, const std::string& breed, int age, const std::string& photo)
{
	dog d{ name,breed,age,photo };
	this->validator.validate(d);
	this->repo.addDog(d);
	this->addDogToShelter(d);

	//this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, d));
	this->undoActions.push_back(new UndoAdd(this->repo, d));
}

void Controller::updateDogToRepository(const std::string& name, const std::string& breed, int age, const std::string& photo)
{
	dog d{ name,breed,age,photo };
	this->validator.validate(d);

	//this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repo, this->repo.findByNameAndBreed(name,breed)));
	this->undoActions.push_back(new UndoUpdate(this->repo, this->repo.findByNameAndBreed(name, breed)));
	this->repo.updateDog(d);
	this->shelter.updateDog(d);
}
//Deletes a dog from the repository.
void Controller::deleteDogFromRepository(const std::string& name, const std::string& breed)
{
	dog d=this->repo.findByNameAndBreed(name, breed);

	this->repo.deleteDog(d);
	this->deleteDogFromShelter(d);

	//this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, d));
	this->undoActions.push_back(new UndoRemove(this->repo, d));
}

//Remove dog from the shelter.
void Controller::deleteDogFromShelter(const dog& d)
{
	
	this->shelter.remove(d);
}
//Adds a dog to the shelter.
void Controller::addDogToShelter(const dog& d)
{
	this->shelter.add(d);
}

void Controller::addAllDogsByBreedToShelter(const std::string& breed)
{
	// get all the dogs from the repository
	std::vector<dog> v = this->repo.getDogs();
	for (auto d:this->repo.getDogs())
	{
		if (d.getBreed() == breed)
			this->shelter.add(d);
	}
}

//Start the shelter.
void Controller::startShelter()
{
	this->shelter.start();
}

//Move to the next dog.
void Controller::nextDogShelter()
{
	this->shelter.next();
}

void Controller::iterDogShelter()
{
	return this->shelter.iter();
}

int Controller::iterThroughtBreeds(const std::string& breed, int age)
{
	int OK = 0, i = 0;
	dog d;
	this->shelter.iter();
	while (OK == 0 && i < this->shelter.getSizeS())
	{
		d = this->shelter.getCurrentDog();
		if (d.getAge() < age && d.getBreed() == breed) OK = 1;
		else
		{
			this->iterDogShelter();
			i++;
		}
	}
	return OK;
}

dog Controller::getCurrentDogShelter()
{
	return this->shelter.getCurrentDog();
}

void Controller::showCurrentImage()
{
	this->shelter.getCurrentImage();
}

void Controller::adoptDog()
{
	dog d = this->getCurrentDogShelter();
	this->getUserList()->add(d);
	this->deleteDogFromRepository(d.getName(), d.getBreed());
}

void Controller::addAllDogsToShelter()
{
	std::vector<dog> doggos = this->repo.getDogs();
	for (auto d : doggos)
	{
		this->shelter.add(d);
	}
}

void Controller::saveUserList()
{
	if (this->user_list == nullptr) return;
	this->user_list->writeToFile();
}

void Controller::displayUserList()
{
	if (this->user_list == nullptr) return;
	this->user_list->displayShelter();
}

void Controller::undo()
{
	if (this->undoActions.empty())
	{
		throw RepositoryException{ "There are no actions to undo." };
	}
	try
	{
		//dog dUpdate= this->undoActions.back().get()->getDog();
		//dUpdate = this->repo.findByNameAndBreed(dUpdate.getName(), dUpdate.getBreed());
		//std::string type = this->undoActions.back().get()->getType();

		//if (type == "UndoUpdate") this->redoActions.push_back(std::make_unique<UndoUpdate>(this->repo, dUpdate));
		this->redoActions.push_back(this->undoActions.back()->getType());

		this->undoActions.back()->executeUndo();

		//dog d=this->undoActions.back().get()->getDog();

		//if(type=="UndoAdd") this->redoActions.push_back(std::make_unique<UndoRemove>(this->repo, d));
		//if (type == "UndoRemove") this->redoActions.push_back(std::make_unique<UndoAdd>(this->repo, d));

		this->undoActions.pop_back();
	}
	catch (RepositoryException& e)
	{
		throw e;
	}
}

void Controller::redo()
{
	if (this->redoActions.empty())
	{
		throw RepositoryException{ "There are no actions to redo." };
	}
	try
	{
		//dog dUpdate = this->redoActions.back().get()->getDog();
		//dUpdate = this->repo.findByNameAndBreed(dUpdate.getName(), dUpdate.getBreed());
		//std::string type = this->redoActions.back().get()->getType();
		//if (type == "UndoUpdate") this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repo, dUpdate));

		this->undoActions.push_back(this->redoActions.back()->getType());

		this->redoActions.back()->executeUndo();

		//dog d = this->redoActions.back().get()->getDog();

		//if (type == "UndoAdd") this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, d));
		//if (type == "UndoRemove") this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, d));

		this->redoActions.pop_back();
	}
	catch (RepositoryException& e)
	{
		throw e;
	}
	//if (this->redoActions.empty())
	//{
	//	throw RepositoryException{ "There are no actions to redo." };
	//}
	//if (this->redoActions.size() == this->undoActions.size())
	//{
	//	throw RepositoryException{ "There are no actions to redo." };
	//}
	//try
	//{
	//	this->redoActions.back()->executeUndo();
	//	this->redoActions.pop_back();
	//}
	//catch (RepositoryException& e)
	//{
	//	throw e;
	//}
}