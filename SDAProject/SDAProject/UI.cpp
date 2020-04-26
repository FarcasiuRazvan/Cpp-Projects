#include "UI.h"
#include <iostream>
#include "Iterator.h"

using namespace std;

void UI::run()
{
	while (true)
	{
		printMenu();
		int cmd;
		cin >> cmd;
		cin.ignore();
		
		if (cmd == 5)
		{
			this->ctrl.add("este", 740);
			this->ctrl.add("este1", 740);
			this->ctrl.add("este2", 741);
			this->ctrl.add("este3", 742);
		}
		else if (cmd == 0) break;
		else if (cmd == 1) this->display();
		else if (cmd == 2) this->add();
		else if (cmd == 3) this->remove();
		else if (cmd == 4) this->check();
		else cout << "You entered a wrong command!" << endl;
	}
}

void UI::printMenu()
{
	cout << "MENU" << endl;
	cout << "1. Display the database." << endl;
	cout << "2. Add an employee." << endl;
	cout << "3. Remove an employee." << endl;
	cout << "4. Check if an employee exists in the database." << endl;
	cout << "0. Exit." << endl;
	cout << "Enter your command: ";
}

void UI::add()
{
	cout << "Enter the name of the employee: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the Telephone Number of the employee: ";
	int number;
	cin >> number;
	cin.ignore();
	this->ctrl.add(name, number);
}

void UI::remove()
{
	cout << "Enter the name of the employee: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the Telephone Number of the employee: ";
	int number;
	cin >> number;
	cin.ignore();
	this->ctrl.remove(name, number);

}

void UI::display()
{
	IteratorS it(this->ctrl.getSet());
	int size = this->ctrl.getSet()->getSize();
	cout << "Employee: " << it.getCurrent()->getElem().getName() << " Telephone No. : " << it.getCurrent()->getElem().getTelNo() << endl;
	for(int i=1;i<size;i++)
	{
		it.next();
		cout << "Employee: " << it.getCurrent()->getElem().getName() << " Telephone No. : " << it.getCurrent()->getElem().getTelNo() << endl;
	}
	
}

void UI::check()
{
	cout << "Enter the name of the employee: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the Telephone Number of the employee: ";
	int number;
	cin >> number;
	cin.ignore();
	if (this->ctrl.check(name,number) == true) cout << "The employee does exist!"<<endl;
	else cout << "The employee does not exist!" << endl;
}
