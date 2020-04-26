#pragma once
#include <iostream>
#include <assert.h>
#include <vector>
#include "dog.h"
#include "Controller.h"
#include "Repository.h"
#include "Shelter.h"
#include "RepositoryExceptions.h"
#include "DogValidator.h"

using namespace std;

void testDog()
{
	dog di;
	dog d1("etc", "etc", 12, "etc");
	dog d("etc", "etc", 12, "etc");
	dog d2("etc1", "etc", 12, "etc");
	assert(d1 == d);
	assert((d1 == d2) == 0);
	assert(d.getAge() == 12);
	assert(d.getName() == "etc");
	assert(d.getBreed() == "etc");
	assert(d.getPhoto() == "etc");
	d.image();
	dog d3("e", "e", 0, "e");
	DogValidator v;
	try
	{
		v.validate(d3);
	}
	catch (DogException& d)
	{
		assert(d.getErrors()[0]== "The breed cannot be less than 2 characters!\n");
		assert(d.getErrors()[1] == string("The name must start with a capital letter!\n"));
	}
}
void testController()
{
	
	Repository repo1{"tst.txt"};
	FileShelter* p1 = new CSVShelter{ "Shelter1.csv" };
	Controller ctrlCSV{ repo1,p1 };

	Repository repo2{ "tst.txt" };
	FileShelter* p2 = new HTMLShelter{ "Shelter1.html" };
	Controller ctrlHTML{ repo2,p2 };

	try
	{
		Repository repo3{ "tst1.txt" };
		FileShelter* p3 = new HTMLShelter{ "Shelter1.html" };
		Controller ctrlHTML1{ repo3,p3 };
	}
	catch (FileException&)
	{

	}
	try
	{
		Repository repo3{ "tst.txt" };
		FileShelter* p3 = new HTMLShelter{ "Shelter1.html" };
		Controller ctrlHTML1{ repo3,p3 };
	}
	catch (FileException&)
	{

	}
	try
	{
		Repository repo4{ "tst1.txt" };
		FileShelter* p4 = new CSVShelter{ "Shelter1.csv" };
		Controller ctrlCSV1{ repo4,p4 };
	}
	catch (FileException&)
	{
		
	}
	try
	{
		Repository repo4{ "tst.txt" };
		FileShelter* p4 = new CSVShelter{ "Shelter1.csv" };
		Controller ctrlCSV1{ repo4,p4 };
	}
	catch (FileException&)
	{

	}
	int etc;
	try
	{
		ctrlCSV.addDogToRepository("Etc1", "etc1", 12, "etc1");
		assert(ctrlCSV.getSizeRepo() == 1);
		ctrlCSV.addDogToRepository("Etc1", "etc1", 12, "etc1");
	}
	catch (DogException& e)
	{
		assert(e.getErrors().size() != 0);
	}
	catch (RepositoryException& e)
	{
		assert(e.what() == "There is another dog with the same name and breed!");
	}
	catch (FileException& e)
	{
		assert(e.what() != NULL);
	}
	
	
	try
	{
		ctrlCSV.updateDogToRepository("Etc1", "etc1", 12, "etc2");
		assert(ctrlCSV.getRepo().findByNameAndBreed("Etc1", "etc1").getPhoto() == "etc2");
		ctrlCSV.updateDogToRepository("Etc2", "etc1", 12, "etc2");
	}
	catch (DogException& e)
	{
		assert(e.getErrors().size() != 0);
	}
	catch (RepositoryException& e)
	{
		assert(e.what() == "There is no dog with the name and breed you entered!");
	}
	catch (FileException& e)
	{
		assert(e.what() != NULL);
	}

	try
	{
		ctrlCSV.deleteDogFromRepository("Etc1","etc1");
		assert(ctrlCSV.getSizeRepo() == 0);
		ctrlCSV.addDogToRepository("Etc2", "etc1", 12, "etc2");
		ctrlCSV.addDogToRepository("Etc3", "etc1", 12, "etc2");
		ctrlCSV.deleteDogFromRepository("Etc2", "etc1");
		assert(ctrlCSV.getSizeRepo() == 1);
		ctrlCSV.deleteDogFromRepository("Etc1", "etc1");
	}
	catch (DogException& e)
	{
		assert(e.getErrors().size() != 0);
	}
	catch (RepositoryException& e)
	{
		assert(e.what() == "There is no dog with the name and breed you entered!");
	}
	catch (FileException& e)
	{
		assert(e.what() != NULL);
	}

	ctrlCSV.addAllDogsByBreedToShelter("etc1");
	assert(ctrlCSV.getSizeShelter() == 1);

	assert(ctrlCSV.isEmptyShelter()==0);
	ctrlCSV.startShelter();
	ctrlCSV.showCurrentImage();
	ctrlCSV.nextDogShelter();
	ctrlCSV.iterDogShelter();
	//ctrlCSV.iterThroughtBreeds("etc1",100);
	dog d = ctrlCSV.getCurrentDogShelter();
	assert(d.getName() == "Etc3");

	ctrlCSV.adoptDog();
	assert(ctrlCSV.getSizeRepo() == 0);

	std::vector<dog> v = ctrlCSV.getAdoptionList();
	assert(v.size() == 1);

	try
	{
		ctrlCSV.saveUserList();

		assert(ctrlCSV.getUserList() != nullptr);
		
	}
	catch (FileException& e)
	{
		assert(e.what() != NULL);
	}
	ctrlCSV.getUserList()->writeToFile();
	ctrlCSV.getUserList()->displayShelter();
	ctrlHTML.addDogToRepository("Etc1", "etc", 1, "etc");
	ctrlHTML.addAllDogsToShelter();
	ctrlHTML.startShelter();
	ctrlHTML.adoptDog();
	ctrlHTML.getUserList()->writeToFile();
	ctrlHTML.displayUserList();
	
	Repository repo11{ "tst.txt.txt" };
	FileShelter* p11 = new CSVShelter{ "Shelter11.csv" };
	Controller ctrlCSV11{ repo11,p11 };
	
delete p1;
delete p2;
}

void testAll()
{
	testDog();
	//testRepo();
	testController();
	//testShelter();

}

