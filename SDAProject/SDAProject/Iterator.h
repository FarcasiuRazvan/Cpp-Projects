#pragma once
#include "set.h"
#include <iostream>

using namespace std;

class IteratorS
{
private:
	node *current;
	int currentPos;
	Set* s;

public:
	IteratorS(Set *s) : current(s->getT()[s->getM() - 1]), currentPos(s->getM()-1), s(s)
	{
		int ok = 1;
		while (this->current->getElem().getTelNo() == 0 && this->valid() == true)
		{
			this->current = this->s->getT()[this->currentPos];
			this->currentPos --;
			ok = 0;
		}
		if(ok==0) this->currentPos ++;
	};
	
	node* getCurrent() { return this->current; };
	int getCurrentPos() { return this->currentPos; };
	void next();
	bool valid();
};