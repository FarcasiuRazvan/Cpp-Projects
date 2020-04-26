#include "QtGuiClass.h"
#include "qstandarditemmodel.h"
#include <QtCore>
#include "ImageDelegate.h"


QtGuiClass::QtGuiClass(Model *m, QWidget *parent)
	: model{ m }, QWidget(parent)
{
	ui.setupUi(this);
	ui.tableView->setItemDelegate(new ImageDelegate{});
	//ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	//ui.tableView->resizeColumnsToContents();
	ui.tableView->setModel(model);
}

void QtGuiClass::setModel()
{
	ui.tableView->setModel(this->model);
}

QtGuiClass::~QtGuiClass()
{
}
