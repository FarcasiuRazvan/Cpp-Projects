#include "MyGUI.h"

GUI::GUI(Controller& c, bool File) : ctrl(c) ,File(File)//userWidget(userWidget), File(File)QtGuiClass& userWidget,
{
	this->initGUI();

	QObject::connect(this->csvButton, &QPushButton::clicked, this, [this]() 
	{
		if (this->File == false)
		{
			this->ctrl.user_list = new CSVShelter{ "C:\\Users\\Wolf\\source\\repos\\lab 10-12\\lab 10-12\\Shelter.csv" };
			QMessageBox msgBox;
			msgBox.setText("Your file has a CSV type !");
			msgBox.exec();
			this->File = true;
		}
		else
		{
			QMessageBox::warning(this, "Warning", "Your file already has a type !");
		}
	});
	QObject::connect(this->htmlButton, &QPushButton::clicked, this, [this]() 
	{
		if (this->File == false)
		{
			this->ctrl.user_list = new HTMLShelter{ "C:\\Users\\Wolf\\source\\repos\\lab8-9part2\\lab8-9part2\\Shelter.html" };
			QMessageBox msgBox;
			msgBox.setText("Your file has a HTML type !");
			msgBox.exec();
			this->File = true;
		}
	});
	QObject::connect(this->populateButton, &QPushButton::clicked, this, &GUI::populateAdminList);
	QObject::connect(this->clearButton, &QPushButton::clicked, this, [this]() {this->clearList(); });
	QObject::connect(this->addButton, &QPushButton::clicked, this, [this]() {this->addDogToRepo(); });
	QObject::connect(this->updateButton, &QPushButton::clicked, this, [this]() {this->updateDogToRepo(); });
	QObject::connect(this->removeButton, &QPushButton::clicked, this, [this]() {this->deleteDogFromRepo(); });
	QObject::connect(this->showButton, &QPushButton::clicked, this, [this]() {if (this->showCond == true) this->showDogs(); else this->showDogsCond(); });
	QObject::connect(this->nextButton, &QPushButton::clicked, this, [this]() 
	{ 
		if (this->showCond == true) this->nextDog(); 
		else 
		{ 
			int age = this->edit6->text().toInt();
			std::string str = this->edit5->text().toStdString();
			this->nextDogCond(str,age); 
		} 
	});
	QObject::connect(this->addAllDogsButton, &QPushButton::clicked, this, [this]() {this->showCond = true; this->addAllDogsToShelter(); });
	QObject::connect(this->addAllDogsByBreedButton, &QPushButton::clicked, this, [this]() {this->showCond = false; this->addAllDogsByBreedToShelter(); });
	QObject::connect(this->adoptButton, &QPushButton::clicked, this, [this]() 
	{ 
		this->adoptDog(); 
		//this->userWidget.setModel();
		//this->userWidget.
	});
	QObject::connect(this->saveButton, &QPushButton::clicked, this, [this]() { this->saveUserListToFile(); });
	QObject::connect(this->undoButton, &QPushButton::clicked, this, [this]() { this->undo(); });
	QObject::connect(this->redoButton, &QPushButton::clicked, this, [this]() { this->redo(); });
	QObject::connect(this->box, &QComboBox::currentTextChanged, [&]() 
	{
		this->adminList->clear();
		if(this->box->currentText()=="Detailed description")
			for (dog d : this->ctrl.getRepo().getDogs())
			{
				QString s = QString::fromStdString(d.getName() + "   " + d.getBreed() + "   " + std::to_string(d.getAge()) + "   " + d.getPhoto());
				this->adminList->addItem(s);
			}
		else
			for (dog d : this->ctrl.getRepo().getDogs())
			{
				QString s = QString::fromStdString(d.getName() + "   " + d.getBreed());
				this->adminList->addItem(s);
			}
	});
	QObject::connect(this->showUserListButton, &QPushButton::clicked, this, [this]() 
	{
		Model *mod = new Model{ this->ctrl };
		QtGuiClass *view=new QtGuiClass( mod );
		view->show();
	});
}
GUI::~GUI()
{
}
void GUI::initGUI()
{
	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	this->box = new QComboBox;

	QVBoxLayout *leftLayout = new QVBoxLayout();
	QVBoxLayout *midLayout = new QVBoxLayout();
	QVBoxLayout *rightLayout = new QVBoxLayout();

	this->adminList = new QListWidget();
	this->userList = new QListWidget();
	this->shelterList = new QListWidget();

	QHBoxLayout *bottomLeft1 = new QHBoxLayout();
	QHBoxLayout *bottomLeft2 = new QHBoxLayout();
	QHBoxLayout *bottomLeft3 = new QHBoxLayout();
	QHBoxLayout *bottomLeft4 = new QHBoxLayout();

	QLabel *label = new QLabel("Name");
	QLabel *label1 = new QLabel("Breed");
	QLabel *label2 = new QLabel("Age");
	QLabel *label3 = new QLabel("Photo link");
	QLabel *label4 = new QLabel("ADMINISTRATOR");
	QLabel *label5 = new QLabel("USER");
	QLabel *label6 = new QLabel("SHELTER");

	this->edit1 = new QLineEdit();
	bottomLeft1->addWidget(label);
	bottomLeft1->addWidget(this->edit1);
	
	this->edit2 = new QLineEdit();
	bottomLeft2->addWidget(label1);
	bottomLeft2->addWidget(this->edit2);

	this->edit3 = new QLineEdit();
	bottomLeft3->addWidget(label2);
	bottomLeft3->addWidget(this->edit3);

	this->edit4 = new QLineEdit();
	bottomLeft4->addWidget(label3);
	bottomLeft4->addWidget(this->edit4);

	this->populateButton = new QPushButton("Populate");
	this->clearButton = new QPushButton("Clear");
	this->undoButton = new QPushButton("Undo");
	this->redoButton = new QPushButton("Redo");
	this->csvButton = new QPushButton("CSV");
	this->htmlButton = new QPushButton("HTML");

	leftLayout->addWidget(label4);
	leftLayout->addWidget(csvButton);
	leftLayout->addWidget(htmlButton);
	leftLayout->addWidget(populateButton);
	leftLayout->addWidget(clearButton);
	leftLayout->addWidget(undoButton);
	leftLayout->addWidget(redoButton);

	this->box->addItem("Detailed description");
	this->box->addItem("Short description");

	rightLayout->addWidget(label5);

	leftLayout->addWidget(this->box);
	leftLayout->addWidget(this->adminList);
	rightLayout->addWidget(this->userList);
	this->saveButton = new QPushButton("Save to File");
	rightLayout->addWidget(saveButton);
	this->showUserListButton = new QPushButton("Show the user list");
	rightLayout->addWidget(showUserListButton);

	leftLayout->addLayout(bottomLeft1);
	leftLayout->addLayout(bottomLeft2);
	leftLayout->addLayout(bottomLeft3);
	leftLayout->addLayout(bottomLeft4);

	this->addButton = new QPushButton("Add");
	this->removeButton = new QPushButton("Remove");
	this->updateButton = new QPushButton("Update");
	this->clearButton->setMinimumWidth(100);
	this->shelterList->setMaximumHeight(30);

	leftLayout->addWidget(removeButton);
	leftLayout->addWidget(addButton);
	leftLayout->addWidget(updateButton);

	midLayout->addWidget(label6);


	this->addAllDogsButton = new QPushButton("AddAll");
	midLayout->addWidget(addAllDogsButton);

	QLabel *label10 = new QLabel("Breed");

	QHBoxLayout *bottomMid3 = new QHBoxLayout();
	this->edit7 = new QLineEdit();
	bottomMid3->addWidget(label10);
	bottomMid3->addWidget(this->edit7);
	midLayout->addLayout(bottomMid3);

	this->addAllDogsByBreedButton = new QPushButton("AddAllByBreed");
	midLayout->addWidget(addAllDogsByBreedButton);

	QLabel *label7 = new QLabel("Breed");
	QLabel *label8 = new QLabel("Age");
	QLabel *label9 = new QLabel("NOW SHOWING");
	QLabel *label11 = new QLabel("FOR SHOWING CONDITION");
	QHBoxLayout *bottomMid2 = new QHBoxLayout();
	bottomMid2->addWidget(label11);

	QHBoxLayout *bottomMid1 = new QHBoxLayout();
	this->edit5 = new QLineEdit();
	bottomMid1->addWidget(label7);
	bottomMid1->addWidget(this->edit5);

	this->edit6 = new QLineEdit();
	bottomMid1->addWidget(label8);
	bottomMid1->addWidget(this->edit6);

	midLayout->addLayout(bottomMid2);
	midLayout->addLayout(bottomMid1);

	this->showButton = new QPushButton("Show");
	this->nextButton = new QPushButton("Next");
	this->adoptButton = new QPushButton("Adopt");

	midLayout->addWidget(label9);

	midLayout->addWidget(this->shelterList);
	midLayout->addWidget(showButton);
	midLayout->addWidget(nextButton);
	midLayout->addWidget(adoptButton);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(midLayout);
	mainLayout->addLayout(rightLayout);
}
void GUI::populateAdminList()
{
	for (dog d : this->ctrl.getRepo().getDogs())
	{
		QString s = QString::fromStdString(d.getName() + "   " + d.getBreed() + "   " + std::to_string(d.getAge()) + "   " + d.getPhoto());
		this->adminList->addItem(s);
	}
}
void GUI::populateUserList()
{
	for (dog d : this->ctrl.getAdoptionList())
	{
		QString s = QString::fromStdString(d.getName() + "   " + d.getBreed() + "   " + std::to_string(d.getAge()) + "   " + d.getPhoto());
		this->userList->addItem(s);
	}
}
void GUI::writeToList()
{
	QString s = this->edit1->text()+" "+ this->edit2->text()+" "+ this->edit3->text()+" "+ this->edit4->text();
	this->adminList->addItem(s);
}
void GUI::clearList()
{
	this->adminList->clear();
}
void GUI::addDogToRepo()
{
	try
	{
		std::string name = this->edit1->text().toStdString();
		std::string breed = this->edit2->text().toStdString();
		int age= this->edit3->text().toInt();
		std::string photo = this->edit4->text().toStdString();
		this->ctrl.addDogToRepository(name,breed,age,photo);
		this->writeToList();
	}
	catch (DogException& e)
	{
		std::string message = "";
		for (auto s : e.getErrors())
			message=message+" "+s;
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
	catch (RepositoryException& e)
	{
		std::string message = e.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
	catch (FileException& e)
	{
		std::string message = e.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
}
void GUI::updateDogToRepo()
{
	try
	{
		std::string name = this->edit1->text().toStdString();
		std::string breed = this->edit2->text().toStdString();
		int age = this->edit3->text().toInt();
		std::string photo = this->edit4->text().toStdString();
		this->ctrl.updateDogToRepository(name, breed, age, photo);
		this->clearList();
		this->populateAdminList();
	}
	catch (DogException& e)
	{
		std::string message = "";
		for (auto s : e.getErrors())
			message = message + " " + s;
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
	catch (RepositoryException& e)
	{
		std::string message = e.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
	catch (FileException& e)
	{
		std::string message = e.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
}
void GUI::deleteDogFromRepo()
{
	try
	{
		std::string name = this->edit1->text().toStdString();
		std::string breed = this->edit2->text().toStdString();
		std::vector<dog> dogs = this->ctrl.getRepo().getDogs();
		for (int i = 0; i < dogs.size(); i++)
			if (dogs[i].getName() == name && dogs[i].getBreed() == breed) delete this->adminList->item(i);

		this->ctrl.deleteDogFromRepository(name, breed);
	}
	catch (DogException& e)
	{
		std::string message = "";
		for (auto s : e.getErrors())
			message = message + " " + s;
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
	catch (RepositoryException& e)
	{
		std::string message = e.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
	catch (FileException& e)
	{
		std::string message = e.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
}
void GUI::addAllDogsByBreedToShelter()
{
	QMessageBox msgBox;
	msgBox.setText("The dogs have been added to the Shelter !");
	msgBox.exec();
	std::string breed = this->edit7->text().toStdString();
	this->ctrl.addAllDogsByBreedToShelter(breed);
}
void GUI::showDogs()
{
	if (this->ctrl.isEmptyShelter())
	{
		QMessageBox::warning(this, "Warning", "Nothing to show, the shelter is empty.");
		this->shelterList->clear();
		return;
	}
	this->ctrl.startShelter();
	this->ctrl.showCurrentImage();
	dog d = this->ctrl.getCurrentDogShelter();
	QString s = QString::fromStdString(d.getName() + "   " + d.getBreed() + "   " + std::to_string(d.getAge()));
	this->shelterList->addItem(s);
}
void GUI::nextDog()
{
	if (this->ctrl.isEmptyShelter())
	{
		QMessageBox::warning(this, "Warning", "Nothing to show, the shelter is empty.");
		this->shelterList->clear();
		return;
	}
	if(this->shelterList->count()!=0) this->shelterList->clear();
	this->ctrl.nextDogShelter();
	dog d = this->ctrl.getCurrentDogShelter();
	QString s = QString::fromStdString(d.getName() + "   " + d.getBreed() + "   " + std::to_string(d.getAge()));
	this->shelterList->addItem(s);
}
void GUI::showDogsCond()
{
	int age = this->edit6->text().toInt();
	std::string breed = this->edit5->text().toStdString();

	if (this->ctrl.isEmptyShelter())
	{
		QMessageBox::warning(this, "Warning", "Nothing to show, the shelter is empty !");
		this->shelterList->clear();
		return;
	}
	this->ctrl.startShelter();

	dog d;
	int OK = this->ctrl.iterThroughtBreeds(breed, age);
	if (OK == 0)
	{
		QMessageBox::warning(this, "Warning", "This breed doesn't exist or the ages of dogs are bigger than the age you entered.");
		return;
	}
	d = this->ctrl.getCurrentDogShelter();
	this->ctrl.showCurrentImage();

	QString s = QString::fromStdString(d.getName() + "   " + d.getBreed() + "   " + std::to_string(d.getAge()));
	this->shelterList->addItem(s);
	
}
void GUI::nextDogCond(const std::string& breed, int age)
{
	if (this->ctrl.isEmptyShelter())
	{
		QMessageBox::warning(this, "Warning", "Nothing to show, the shelter is empty.");
		this->shelterList->clear();
		return;
	}
	if (this->shelterList->count() != 0) this->shelterList->clear();

	dog d;
	int OK = this->ctrl.iterThroughtBreeds(breed, age);
	if (OK == 0)
	{
		QMessageBox::warning(this, "Warning", "This breed doesn't exist or the ages of dogs are bigger than the age you entered.");
		return;
	}

	d = this->ctrl.getCurrentDogShelter();
	this->ctrl.showCurrentImage();

	QString s = QString::fromStdString(d.getName() + "   " + d.getBreed() + "   " + std::to_string(d.getAge()));
	this->shelterList->addItem(s);
}
void GUI::adoptDog()
{
	QMessageBox msgBox;
	msgBox.setText("The dog has been adopted !");
	msgBox.exec();
	this->ctrl.adoptDog();
	this->nextDog();
	this->clearList();
	this->populateAdminList();
	this->userList->clear();
	this->populateUserList();
}
void GUI::addAllDogsToShelter()
{
	QMessageBox msgBox;
	msgBox.setText("All repo dogs have been added to the Shelter !");
	//msgBox.
	msgBox.exec();
	this->ctrl.addAllDogsToShelter();
}
void GUI::saveUserListToFile()
{
	try
	{
		this->ctrl.saveUserList();

		if (this->ctrl.getUserList() == nullptr)
		{
			QMessageBox::warning(this, "Warning", "Shelter cannot be saved!" );
			return;
		}

		QMessageBox msgBox;
		msgBox.setText("The user list has been saved !");
		msgBox.exec();
	}
	catch (FileException& e)
	{
		std::string message = e.what();
		QMessageBox::warning(this, "Warning", QString::fromStdString(message));
	}
}
void GUI::undo()
{
	try
	{
		this->ctrl.undo();
		QMessageBox msgBox;
		msgBox.setText("Succesful undo !");
		msgBox.exec();
		this->clearList();
		this->populateAdminList();
	}
	catch (RepositoryException& e)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(e.what()));
	}
}
void GUI::redo()
{
	try
	{
		this->ctrl.redo();
		QMessageBox msgBox;
		msgBox.setText("Succesful redo !");
		msgBox.exec();
		this->clearList();
		this->populateAdminList();
	}
	catch (RepositoryException& e)
	{
		QMessageBox::warning(this, "Warning", QString::fromStdString(e.what()));
	}
}