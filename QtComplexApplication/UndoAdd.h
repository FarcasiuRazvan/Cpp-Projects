#pragma once
#include "Undo.h"

class UndoAdd : public UndoAction
{
private:
	dog addedDog;
	Repository& repo;
	std::string type;
	//Controller &ctrl;
public:
	//UndoAdd(Controller &_ctrl, const dog& d) : ctrl{ _ctrl }, addedDog{ d } {}
	UndoAdd(Repository& _repo, const dog& d) : repo{ _repo }, addedDog{ d }, type{ "UndoAdd" } {}
	void executeUndo() override
	{
		try
		{
			this->repo.deleteDog(addedDog);
			//this->ctrl.deleteDogFromRepository(addedDog.getName(), addedDog.getBreed());
		}
		catch (RepositoryException& e)
		{
			throw e;
		}
	}

	dog getDog() override { return this->addedDog; }
	UndoAction* getType()override
	{
		UndoRemove* uRemove = new UndoRemove(this->repo, this->addedDog);
		return uRemove;
	}
};