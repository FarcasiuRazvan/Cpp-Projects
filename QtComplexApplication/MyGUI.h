#pragma once
#include <QtWidgets>
#include <vector>
#include <cstring>
#include "Controller.h"
#include "CSVShelter.h"
#include "HTMLShelter.h"
#include "RepositoryExceptions.h"
#include "QtGuiClass.h"


class GUI : public QWidget
{
public:
	GUI(Controller& c, bool File);// QtGuiClass& userWidget, bool File);
	~GUI();

private:
	Controller &ctrl;
	bool showCond;
	bool File;
	QListWidget *adminList, *userList, *shelterList;
	QLineEdit *edit1, *edit2, *edit3, *edit4, *edit5, *edit6, *edit7;
	QPushButton *csvButton,*htmlButton,*populateButton, *clearButton, *addButton, *removeButton, *passButton, *updateButton, *showButton, *nextButton, *addAllDogsButton, *addAllDogsByBreedButton, *adoptButton, *saveButton, *undoButton, *redoButton, *showUserListButton;
	QComboBox *box;
	//QtGuiClass &userWidget;

	void initGUI();
	void populateAdminList();
	void populateUserList();
	void writeToList();
	void clearList();
	void addDogToRepo();
	void updateDogToRepo();
	void deleteDogFromRepo();


	//void addDogToShelter();
	//void deleteDogFromShelter();
	void addAllDogsByBreedToShelter();
	void showDogs();
	void nextDog();
	void showDogsCond();
	void nextDogCond(const std::string& breed, int age);
	void adoptDog();
	void addAllDogsToShelter();
	void saveUserListToFile();
	void undo();
	void redo();
};

