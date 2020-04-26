#include "Iterator.h"

void IteratorS::next()
{
	if(this->current->getNext()==nullptr)
	{
		this->currentPos--;
		this->current= this->s->getT()[this->currentPos];
		int ok = 1;
		while (this->current->getElem().getTelNo() == 0 && this->valid() == true)
		{
			ok = 0;
			this->current = this->s->getT()[this->currentPos];
			this->currentPos--;
		}
		if (ok == 0) this->currentPos++;
	}
	else
	{
		this->current = this->current->getNext();
	}


}

bool IteratorS::valid()
{
	if (this->currentPos >= 0) return true;
	return false;
}
