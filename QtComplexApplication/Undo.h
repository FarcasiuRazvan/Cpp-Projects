#pragma once

#include "Dog.h"
#include "Repository.h"
#include "Controller.h"
#include "RepositoryExceptions.h"
#include "UndoAdd.h"

class UndoAction
{
public:
	UndoAction() {};
	virtual void executeUndo() = 0;
	virtual ~UndoAction() {};
	virtual dog getDog()=0;
	virtual std::string getType()=0;
};

class UndoRemove : public UndoAction
{
private:
	dog deletedDog;
	Repository& repo;
	std::string type;
	//Controller& ctrl;
public:
	//UndoRemove(Controller& _ctrl, const dog& d) : ctrl{ _ctrl }, deletedDog{ d } {}
	UndoRemove(Repository& _repo, const dog& d) : repo{ _repo }, deletedDog{ d }, type{"UndoRemove"} {}

	void executeUndo() override
	{
		//this->ctrl.addDogToRepository(deletedDog.getName(), deletedDog.getBreed(), deletedDog.getAge(), deletedDog.getPhoto());
		try
		{
			this->repo.addDog(deletedDog);
		}
		catch (RepositoryException& e)
		{
			throw e;
		}
	}

	dog getDog() { return this->deletedDog; }
	std::string getType()override
	{
		//UndoA *uAdd = new UndoAdd(this->repo, this->deletedDog);
		return type;
	}
};

class UndoUpdate : public UndoAction
{
private:
	dog updatedDog;
	Repository& repo;
	std::string type;
	//Controller& ctrl;
public:
	//UndoUpdate(Controller& _ctrl, const dog& d) : ctrl{ _ctrl }, updatedDog{ d } {}
	UndoUpdate(Repository& _repo, const dog& d) : repo{ _repo }, updatedDog{ d }, type{"UndoUpdate"} {}

	void executeUndo() override
	{
		try
		{
			this->repo.updateDog(updatedDog);
		}
		catch (RepositoryException& e)
		{
			throw e;
		}
		//this->ctrl.updateDogToRepository(updatedDog.getName(), updatedDog.getBreed(), updatedDog.getAge(), updatedDog.getPhoto());
	}

	dog getDog() { return this->updatedDog; }
	std::string getType()override
	{
		//UndoUpdate *uUpdate = new UndoUpdate(this->repo, this->updatedDog);
		return type;
	}
};