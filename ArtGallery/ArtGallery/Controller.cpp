#include "Controller.h"
#include "Painting.h"

void controller::addPainting(const std::string artist, const std::string title, const int year)
{
	painting p(title, artist, year);
	this->repoAll.addPainting(p);
}
void controller::addPaintingSpecial(const std::string artist, const std::string title, const int year)
{
	painting p(title, artist, year);
	this->repoSpecialStorage.addPainting(p);
}
void controller::removePainting(const std::string artist, const std::string title, const int year)
{
	painting p(title, artist, year);
	this->repoAll.removePainting(p);
}

void controller::removePaintingSpecial(const std::string artist, const std::string title, const int year)
{
	painting p(title, artist, year);
	this->repoSpecialStorage.removePainting(p);
}
void controller::undo()
{

}

void controller::move(const std::string artist, const std::string title, const int year)
{
	this->addPaintingSpecial(title, artist, year);
	this->removePainting(title, artist, year);
}