#include "HTMLShelter.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void HTMLShelter::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	f << "<!DOCTYPE html>"<<endl;
	f << "<html>" << endl;
	f<<"<head>" << endl;
	f<<"<title>HTML_Dogs</title>" << endl;
	f<<"</head>" << endl;
	f<<"<body>" << endl;
	f<<"<table border=\"1\">" << endl;

	f << "<tr>" << endl;
	f << "<td>" << "Name" << "</td>" << endl << "<td>" << "Breed" << "</td>" << endl << "<td>" << "Age" << "</td>" << endl << "<td>"<<"Link"<<"</td>" << endl;
	f << "</tr>" << endl;

	for (auto s : this->userList)
	{
		f << "<tr>"<<endl;
		f << "<td>" << s.getName() << "</td>" << endl << "<td>" << s.getBreed() << "</td>" << endl << "<td>" << s.getAge() << "</td>" << endl << "<td><a href=\"" << s.getPhoto() << "\">Link</a></td>" << endl;
		f << "</tr>"<<endl;
	}
	f << "</table>" << endl;
	f << "</body>" << endl;
	f << "</html>" << endl;

	f.close();
}

void HTMLShelter::displayShelter() const
{
	string aux = "\"" + this->filename + "\"";

	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
