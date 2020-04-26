#pragma once
#include "Repository.h"

class controller
{
private:
	repository repoAll;
	repository repoSpecialStorage;

public:
	controller() {};
	
	void addPainting(const std::string artist, const std::string title, const int year);
	void addPaintingSpecial(const std::string artist, const std::string title, const int year);
	void removePainting(const std::string artist, const std::string title, const int year);
	void removePaintingSpecial(const std::string artist, const std::string title, const int year);
	void move(const std::string artist, const std::string title, const int year);

	std::vector<painting> getAll() { return repoAll.getAll(); }
	std::vector<painting> getAllSpecialStorage() { return repoSpecialStorage.getAll(); }

	void undo();
};