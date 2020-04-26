#include "UI.h"
#include <iostream>


using namespace std;

void UI::menu()
{
	cout << "ART GALLERY" << endl;
	cout << "1.Add a new painting." << endl;
	cout << "2.Move a painting from the gallery." << endl;
	cout << "3.Show the gallery." << endl;
	cout << "4.Show the special storage." << endl;
	cout << "5.Undo." << endl;
	cout << "6.Exit." << endl;
}
void UI::addPainting()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);

	cout << "Enter the artist: ";
	std::string artist;
	getline(cin, artist);

	cout << "Enter the year: ";
	int year;
	cin >> year;
	cin.ignore();

	this->ctrl.addPainting(artist, title, year);


}
void UI::movePainting()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);

	cout << "Enter the artist: ";
	std::string artist;
	getline(cin, artist);

	cout << "Enter the year: ";
	int year;
	cin >> year;
	cin.ignore();

	this->ctrl.move(title, artist, year);
}
void UI::showGallery()
{
	std::vector<painting> p = ctrl.getAll();
	for (int i = 0; i < p.size(); i++)
		cout << p[i].getArtist() << " " << p[i].getTitle() << " " << p[i].getYear()<<endl;
}
void UI::showSpecialStorage()
{
	std::vector<painting> p = ctrl.getAllSpecialStorage();
	for (int i = 0; i < p.size(); i++)
		cout << p[i].getArtist() << " " << p[i].getTitle() << " " << p[i].getYear() << endl;
}
//void UI::undo();

void UI::run()
{
	int ok = 0;
	while (ok == 0)
	{
		this->menu();
		cout << "Enter your command: ";
		int cmd;
		cin >> cmd;
		cin.ignore();
		if (cmd == 1)
		{
			this->addPainting();
		}
		if (cmd == 2)
		{
			this->movePainting();
		}
		if (cmd == 3)
		{
			this->showGallery();
		}
		if (cmd == 4)
		{
			this->showSpecialStorage();
		}
		if (cmd == 5);
		if (cmd == 6) ok = 1;
		if (cmd > 6 || cmd < 1) cout << "ERROR: invalid command!" << endl;
	}
}