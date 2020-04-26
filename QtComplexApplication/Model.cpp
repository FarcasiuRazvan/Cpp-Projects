#include "Model.h"
#include "ImageDelegate.h"

Model::Model(Controller &ctrl)
	: ctrl{ctrl}
{
	//ui.setupUi(this);
}

Model::~Model()
{
}

int Model::rowCount(const QModelIndex & parent) const
{
	//return this->ctrl.getRepo().getDogs().size();
	return this->ctrl.getAdoptionList().size();
}

int Model::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant Model::data(const QModelIndex & index, int role) const
{
	dog currentDog = this->ctrl.getAdoptionList()[index.row()];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:		// first column - name
			return QString::fromStdString(currentDog.getName());
		case 1:		// second column - breed
			return QString::fromStdString(currentDog.getBreed());
		case 2:		// third column - age
			return QString::number(currentDog.getAge());
		case 3:		// fourth column - photoLink
		{
			return QString::fromStdString(currentDog.getPhoto());
		}
		default:
			break;
		}
	}

	return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Name" };
			case 1:
				return QString{ "Breed" };
			case 2:
				return QString{ "Age" };
			case 3:
				return QString{ "PhotoLink" };
			default:
				break;
			}
		}
	}

	return QVariant();
}

bool Model::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	int col = index.column();
	
	dog& currentDog = this->ctrl.getAdoptionList()[index.row()];
	
	if (role == Qt::EditRole)
	{
		switch (col)
		{
			case 0:
				break;
			case 1:
				break;
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
		}
	}
	
	emit dataChanged(index, index);
	return true;
}

Qt::ItemFlags Model::flags(const QModelIndex & index) const
{
	int col = index.column();
	if (col == 0 || col == 1)
		return Qt::ItemFlags{};
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}
