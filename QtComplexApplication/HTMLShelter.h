#pragma once
#include "FileShelter.h"
#include <string>

class HTMLShelter : public FileShelter
{
public:
	HTMLShelter(const std::string& filename) { this->filename = filename; }
	//: FileShelter{ filename } {}
	
	/*
	Writes the shelter to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the shelter using Microsof Excel.
	*/
	void displayShelter() const override;
};
