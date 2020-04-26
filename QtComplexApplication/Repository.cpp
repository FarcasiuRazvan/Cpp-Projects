#include "dog.h"
#include "Repository.h"
#include "Utils.h"
#include <string>
#include <fstream>
#include "RepositoryExceptions.h"

using namespace std;

Repository::Repository(const std::string& name)
{
	this->filename = name;
	this->readFromFile();
}

void Repository::addDog(const dog& d)
{
	dog di = this->findByNameAndBreed(d.getName(), d.getBreed());
	dog dit;
	if (di.getName() == dit.getName())
	{
		this->dogs.push_back(d);
		this->writeToFile(this->filename);
	}
	else throw DuplicateDogException();
}

//Deletes a dog from the repository.
void Repository::deleteDog(const dog& d)
{
	int pos = this->findDogPosition(d);
	if (pos == -1) throw ExistDogException();
	
	this->dogs.erase(this->dogs.begin() + pos);

	writeToFile(this->filename);
}

//Update a dog from the repository.
void Repository::updateDog(const dog& d)
{
	int i = -1,ok=1;
	for (auto m:this->dogs)
	{
		i++;
		if (m.getName() == d.getName() && m.getBreed() == d.getBreed())
		{
			this->dogs[i] = d;
			ok = 0;
			writeToFile(this->filename);
		}
	}
	if (ok == 1) throw ExistDogException();
}

int Repository::findDogPosition(const dog& d)
{
	int cont = -1;
	for (auto doggo:this->dogs)
	{
		cont++;
		if (doggo.getName() == d.getName() && doggo.getBreed() == d.getBreed())
		{
			return cont;
		}
	}
	return -1;
}

dog Repository::findByNameAndBreed(const std::string& name, const std::string& breed)
{
	for (auto d:this->dogs)
	{
		if (d.getName() == name && d.getBreed() == breed)
			return d;
	}
	return dog{};
}


void Repository::readFromFile()
{
	ifstream file(this->filename);

	dog s;
	while (file >> s)
		this->dogs.push_back(s);
	
	file.close();
}

void Repository::writeToFile(std::string filen)
{
	ofstream file(filen);

	for (auto s : this->dogs)
	{
		file << s;
	}

	file.close();
}


