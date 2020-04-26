
#include "Shelter.h"

Shelter::Shelter()
{
	this->current = 0;
}

void Shelter::add(const dog &d)
{
	if (this->findDogPosition(d) == -1) this->dogs.push_back(d);
	return;
}

void Shelter::updateDog(const dog& d)
{
	int cont = -1;
	for (auto m : this->dogs)
	{
		cont++;
		if (m.getName() == d.getName() && m.getBreed() == d.getBreed()) this->dogs[cont] = d;
	}
}

void Shelter::remove(const dog& d)
{
	int pos = this->findDogPosition(d);
	if (pos == -1) return;
	if (this->dogs.size() == 1) this->dogs.pop_back();

	int cont = -1, ok = 1;
	for (auto s : this->dogs)
	{
		cont++;
		if (cont == pos + 1) ok = 0;
		if (ok == 0) this->dogs[cont - 1] = this->dogs[cont];
	}

	if (ok == 0) this->dogs.resize(this->dogs.size() - 1);
}

int Shelter::findDogPosition(const dog& d)
{
	int cont = -1;
	for (auto doggo : this->dogs)
	{
		cont++;
		if (doggo.getName() == d.getName() && doggo.getBreed() == d.getBreed())
			return cont;
	}
	return -1;
}

dog Shelter::getCurrentDog()
{
	if (this->current == this->dogs.size())
		this->current = 0;

	if (this->dogs.size() != NULL)
		return this->dogs[this->current];
	return dog{};
}

void Shelter::start()
{
	if (this->dogs.size() == 0) return;
	this->current = 0;
}

void Shelter::next()
{
	if (this->dogs.size() == 0) return;
	this->current++;
	this->getCurrentImage();
}

void Shelter::getCurrentImage()
{
	dog currentDog = this->getCurrentDog();
	currentDog.image();
}

void Shelter::iter()
{
	if (this->dogs.size() == 0) return;
	this->current++;
}

bool Shelter::isEmpty()
{
	return this->dogs.size() == 0;
}

