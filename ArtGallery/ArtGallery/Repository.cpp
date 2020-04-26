#include "Repository.h"

void repository::addPainting(painting p)
{
	this->paintings.push_back(p);
}
void repository::removePainting(painting p)
{
	int ok = 0;
	if (this->paintings[this->paintings.size() - 1].getArtist() == p.getArtist() && p.getYear() == this->paintings[this->paintings.size() - 1].getYear() && p.getTitle() == this->paintings[this->paintings.size() - 1].getTitle())
		this->paintings.pop_back();
	else
	{
		for (int i = 0; i < this->paintings.size(); i++)
		{
			if (p.getArtist() == this->paintings[i].getArtist() && p.getYear() == this->paintings[i].getYear() && p.getTitle() == this->paintings[i].getTitle())
				ok = 1;
			if (ok == 1 && i < this->paintings.size() - 1)
				this->paintings[i] = this->paintings[i + 1];
		}
		this->paintings.pop_back();
	}
}

