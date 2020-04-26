#pragma once

#include <QWidget>
#include "ui_QtGuiClass.h"
#include "Model.h"

class QtGuiClass : public QWidget
{
	Q_OBJECT

public:
	QtGuiClass(Model* model, QWidget *parent = Q_NULLPTR);
	~QtGuiClass();
	void setModel();

private:
	Ui::QtGuiClass ui;
	Model *model;
};