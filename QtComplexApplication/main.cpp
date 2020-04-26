//#include "lab1012.h"
#include <QtWidgets/QApplication>
#include "MyGUI.h"
#include "CSVShelter.h"
#include "Model.h"
#include "QtGuiClass.h"
#include "ImageDelegate.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository repo("Dogs.txt");
	FileShelter* p = nullptr;// new CSVShelter{ "C:\\Users\\Wolf\\source\\repos\\lab 10-12\\lab 10-12\\Shelter.csv" };
	Controller ctrl{ repo,p };

	ctrl.user_list = new CSVShelter{ "C:\\Users\\Wolf\\source\\repos\\lab 10-12\\lab 10-12\\Shelter.csv" };

	//Model *mod = new Model{ctrl};
	//QtGuiClass view{ mod };

	GUI gui{ ctrl ,false // view, false
};
	gui.show();



	return a.exec();
}
