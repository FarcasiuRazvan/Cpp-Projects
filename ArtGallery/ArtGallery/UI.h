#pragma once
#include "Controller.h"

class UI
{
private:
	controller ctrl;
public:
	UI() {};
	void menu();
	void addPainting();
	void movePainting();
	void showGallery();
	void showSpecialStorage();
	void undo();

	void run();
};