#include "UI.h"
#include <string>
#include <vector>
#include "DogValidator.h"
#include "RepositoryExceptions.h"

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode." << endl;
	cout << "2 - User mode." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << "Available commands: " << endl;
	cout << "1 - Add a dog." << endl;
	cout << "2 - Display the dogs" << endl;
	cout << "3 - Delete a dog" << endl;
	cout << "4 - Update a dog" << endl;
	cout << "0 - Back." << endl;
}

void UI::printShelterMenu()
{
	cout << "Available commands: " << endl;
	cout << "1 - Show the dogs." << endl;
	cout << "2 - Show all the dogs of a given breed, having an age less than a given number." << endl;
	cout << "3 - Add all dogs to the shelter" << endl;
	cout << "4 - See the adoption list." << endl;
	cout << "5 - Save adoption list." << endl;
	cout << "6 - Display adoption list." << endl;
	cout << "0 - Back." << endl;
}

void UI::addDogToRepo()
{
	cout << "Enter the dog's name: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the age: ";
	int age;
	cin >> age;
	cin.ignore();
	cout << "Enter the link of the photo: ";
	std::string photo;
	getline(cin, photo);

	try
	{
		this->ctrl.addDogToRepository(name, breed, age, photo);
	}
	catch (DogException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::updateDogToRepo()
{
	cout << "Enter the dog's name: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter the age: ";
	int age;
	cin >> age;
	cin.ignore();
	cout << "Enter the link of the photo: ";
	std::string photo;
	getline(cin, photo);

	try
	{
		this->ctrl.updateDogToRepository(name, breed, age, photo);
	}
	catch (DogException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::deleteDogFromRepo()
{
	cout << "Enter the dog's name: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);
	try
	{
		this->ctrl.deleteDogFromRepository(name, breed);
	}
	catch (DogException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}

}

int UI::deleteDogFromShelter()
{
	cout << "Enter the dog's name: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);
	dog d( name,breed,0,"etc" );
	this->ctrl.deleteDogFromShelter(d);
	return 0;
}


void UI::displayAllDogsRepo()
{
	std::vector<dog> v = this->ctrl.getRepo().getDogs();
	if (v.size() == NULL)
		return;
	if (v.size() == 0)
	{
		cout << "There are no dogs in the repository." << endl;
		return;
	}
	for (auto d : v)
	{
		cout << d.getName() << " " << d.getBreed() << " " << d.getAge() << endl;// " " << d.getPhoto() << endl;
	}
}

void UI::addDogToShelter()
{
	cout << "Enter the name: ";
	std::string name;
	getline(cin, name);
	cout << "Enter the breed: ";
	std::string breed;
	getline(cin, breed);

	//search for the dog in the repository
	Repository r = ctrl.getRepo();
	dog d = r.findByNameAndBreed(name, breed);
	if (d.getName() == ""&& d.getBreed() == "")
	{
		cout << "There are no dogs with the given data in the repository. Nothing will be added to the shelter." << endl;
		return;
	}

	this->ctrl.addDogToShelter(d);
}

void UI::addAllDogsToShelter()
{
	this->ctrl.addAllDogsToShelter();
}

void UI::addAllDogsByBreedToShelter()
{
	cout << "Enter the breed";
	std::string breed;
	getline(cin, breed);

	this->ctrl.addAllDogsByBreedToShelter(breed);
}

void UI::showDogs()
{
	if (this->ctrl.isEmptyShelter())
	{
		cout << "Nothing to show, the shelter is empty." << endl;
		return;
	}
	this->ctrl.startShelter();
	this->ctrl.showCurrentImage();
	dog d = this->ctrl.getCurrentDogShelter();
	cout << "Now showing: " << d.getName() << " - " << d.getBreed() << " at the age of " << d.getAge() << endl;

	cout << "What do you want to do ?" << endl;
	cout << "1. Adopt the dog." << endl;
	cout << "2. Get to the next dog." << endl;
	cout << "3. Exit." << endl;
	int command;
	cin >> command;
	if (command == 1) this->adoptDog();
	if (command == 2) this->nextDog();
	if (command == 3) return;

}

void UI::nextDog()
{
	if (this->ctrl.isEmptyShelter())
	{
		cout << "Nothing to show, the shelter is empty." << endl;
		return;
	}
	this->ctrl.nextDogShelter();
	dog d = this->ctrl.getCurrentDogShelter();
	cout << "Now showing: " << d.getName() << " - " << d.getBreed() << " at the age of " << d.getAge() << endl;

	cout << "What do you want to do ?" << endl;
	cout << "1. Adopt the dog." << endl;
	cout << "2. Get to the next dog." << endl;
	cout << "3. Exit." << endl;
	int command;
	cin >> command;
	if (command == 1) this->adoptDog();
	if (command == 2) this->nextDog();
	if (command == 3) return;
}

void UI::showDogsCond()
{
	cout << "Enter a breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Enter an age: ";
	int age;
	cin >> age;
	if (this->ctrl.isEmptyShelter())
	{
		cout << "Nothing to show, the shelter is empty." << endl;
		return;
	}
	this->ctrl.startShelter();

	dog d;
	int OK = this->ctrl.iterThroughtBreeds(breed, age);
	if (OK == 0)
	{
		cout << "This breed doesn't exist or the ages of dogs are bigger than the age you entered." << endl;
		return;
	}
	d = this->ctrl.getCurrentDogShelter();
	this->ctrl.showCurrentImage();
	cout << "Now showing: " << d.getName() << " - " << d.getBreed() << " at the age of " << d.getAge() << endl;

	cout << "What do you want to do ?" << endl;
	cout << "1. Adopt the dog." << endl;
	cout << "2. Get to the next dog." << endl;
	cout << "3. Exit." << endl;
	int command;
	cin >> command;
	if (command == 1) this->adoptDog();
	if (command == 2) this->nextDogCond(breed, age);
	if (command == 3) return;
}

void UI::nextDogCond(const std::string& breed, int age)
{
	dog d;
	int OK = this->ctrl.iterThroughtBreeds(breed, age);

	d = this->ctrl.getCurrentDogShelter();
	this->ctrl.showCurrentImage();
	cout << "Now showing: " << d.getName() << " - " << d.getBreed() << " at the age of " << d.getAge() << endl;

	cout << "What do you want to do ?" << endl;
	cout << "1. Adopt the dog." << endl;
	cout << "2. Get to the next dog." << endl;
	cout << "3. Exit." << endl;
	int command;
	cin >> command;
	if (command == 1) this->adoptDog();
	if (command == 2) this->nextDogCond(breed, age);
	if (command == 3) return;
}

void UI::adoptDog()
{
	this->ctrl.adoptDog();
}

void UI::displayUserList()
{
	
	std::vector<dog> v = this->ctrl.getAdoptionList();
	if (v.size() == NULL)
		return;
	if (v.size() == 0)
	{
		cout << "There are no adopted dogs." << endl;
		return;
	}
	for (auto d : v)
	{
		cout << d.getName() << " " << d.getBreed() << " " << d.getAge() << endl;// " " << d.getPhoto() << endl;
	}
	
}

void UI::saveUserListToFile()
{
	try
	{
		this->ctrl.saveUserList();

		if (this->ctrl.getUserList() == nullptr)
		{
			cout << "Shelter cannot be displayed!" << endl;
			return;
		}
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}

}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addDogToRepo();
					break;
				case 2:
					this->displayAllDogsRepo();
					break;
				case 3:
					this->deleteDogFromRepo();
					break;
				case 4:
					this->updateDogToRepo();
					break;
				}
			}
		}

		// shelter management
		if (command == 2)
		{
			while (true)
			{
				UI::printShelterMenu();
				int commandShelter{ 0 };
				cout << "Input the command: ";
				cin >> commandShelter;
				cin.ignore();
				if (commandShelter == 0)
					break;
				switch (commandShelter)
				{
				case 1:
					this->showDogs();
					break;
				case 2:
					this->showDogsCond();
					break;
				case 3:
					this->addAllDogsToShelter();
					break;
				case 4:
					this->displayUserList();
					break;
				case 5:
					this->saveUserListToFile();
					break;
				case 6:
					this->ctrl.displayUserList();
					break;
				}
			}
		}
	}
}