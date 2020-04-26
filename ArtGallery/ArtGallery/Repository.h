#pragma once
#include "Painting.h"
#include <vector>

class repository
{
private:
	std::vector<painting> paintings;
public:
	repository() {};
	void addPainting(painting p);
	void removePainting(painting p);

	std::vector<painting> getAll() { return paintings; }
};
