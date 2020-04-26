#include "set.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

void Set::add(employee & elem)
{
	int pos = this->hashFunction(elem);
	if (this->T[pos]->getElem().getTelNo() == NULL)
	{ 
		this->T[pos]->setElem(elem); 
		this->T[pos]->setNext(nullptr);
		this->size++; 
		
	}
	else
	{
		node* ptr = new node(elem,this->T[pos]);
		this->T[pos] = ptr;
		this->size++;
	}
}

void Set::remove(employee & elem)
{
	if (this->find(elem) == false) return;

	int pos = this->hashFunction(elem);
	node* x = this->T[pos];
	if (x->getElem().getName() == elem.getName() && x->getElem().getTelNo() == elem.getTelNo())
	{
		if (x->getNext() == nullptr) 
		{
			this->T[pos]->setNameEmployee("");
			this->T[pos]->setTelNoEmployee(NULL);
			this->size--;
			return;
		}
		else
		{
			node* y = x;
			this->T[pos] = x->getNext();
			delete y;
			this->size--;
			return;
		}
	}
	node* copie = x->getNext();
	while (x->getNext()!=nullptr)
	{
		node* y = x;
		x = x->getNext();
		if (x->getElem().getName() == elem.getName() && x->getElem().getTelNo() == elem.getTelNo())
		{
			if (x->getNext() == nullptr)
			{
				y->setNext(nullptr);
				delete x;
				this->size--;
				return;
			}
			else
			{
				y->setNext(x->getNext());
				delete x;
				this->size--;
				return;
			}
		}
	}
	
}

bool Set::find(employee & elem)
{
	int pos = this->hashFunction(elem);
	node* x = this->T[pos];
	
	if (x->getElem().getName() == elem.getName() && x->getElem().getTelNo() == elem.getTelNo())
	{
		return true;
	}
	
	while (x->getNext() != nullptr)
	{
		x = x->getNext();
		if (x->getElem().getName() == elem.getName() && x->getElem().getTelNo() == elem.getTelNo())
		{
			return true;
		}
	}
	return false;
}

