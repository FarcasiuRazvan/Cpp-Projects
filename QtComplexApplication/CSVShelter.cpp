#include "CSVShelter.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void CSVShelter::writeToFile()
{
	ofstream f(this->filename);

	for (auto s : this->userList)
		f << s;

	f.close();
}

void CSVShelter::displayShelter() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
