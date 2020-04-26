#pragma once

#include "Dog.h"
#include "Repository.h"
#include "Controller.h"
#include "RepositoryExceptions.h"

class RedoAction
{
public:
	virtual void executeRedo() = 0;
	virtual ~RedoAction() {};
};

class RedoAdd : public RedoAction
{
private:
	dog deletedDog;
	Repository& repo; 
	//Controller& ctrl;
public:
	//RedoAdd(Controller& _ctrl, const dog& d) : ctrl{ _ctrl }, deletedDog{ d } {}
	RedoAdd(Repository& _repo, const dog& d) : repo{ _repo }, deletedDog{ d } {}

	void executeRedo() override
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
};

class RedoRemove : public RedoAction
{
private:
	dog addedDog;
	Repository& repo;
	//Controller& ctrl;
public:
	//RedoRemove(Controller& _ctrl, const dog& d) : ctrl{ _ctrl }, addedDog{ d } {}
	RedoRemove(Repository& _repo, const dog& d) : repo{ _repo }, addedDog{ d } {}

	void executeRedo() override
	{
		//this->ctrl.deleteDogFromRepository(addedDog.getName(),addedDog.getBreed());
		try
		{
			this->repo.deleteDog(addedDog);
		}

		catch (RepositoryException& e)
		{
			throw e;
		}
	}
};

class RedoUpdate : public RedoAction
{
private:
	dog updatedDog;
	Repository& repo;
	//Controller& ctrl;
public:
	//RedoUpdate(Controller& _ctrl, const dog& d) : ctrl{ _ctrl }, updatedDog{ d } {}
	RedoUpdate(Repository& _repo, const dog& d) : repo{ _repo }, updatedDog{ d } {}

	void executeRedo() override
	{
		//this->ctrl.updateDogToRepository(updatedDog.getName(), updatedDog.getBreed(), updatedDog.getAge(), updatedDog.getPhoto());
		try
		{
			this->repo.updateDog(updatedDog);
		}
		catch (RepositoryException& e)
		{
			throw e;
		}
	}
};