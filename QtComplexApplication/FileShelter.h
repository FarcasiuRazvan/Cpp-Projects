#pragma once
#include "UserList.h"

class FileShelter : public UserList
{
protected:
	std::string filename;

public:
	FileShelter() {}
	FileShelter(const std::string& filename);
	virtual ~FileShelter() {}

	virtual void writeToFile() = 0;
	virtual void displayShelter() const = 0;
};

