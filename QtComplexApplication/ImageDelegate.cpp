#include "ImageDelegate.h"
#include <QPixmap>
#include <QPainter>

ImageDelegate::ImageDelegate(QWidget *parent)
	: QStyledItemDelegate(parent)
{
	//ui.setupUi(this);
}

void ImageDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QString organism = index.model()->data(index, Qt::EditRole).toString();

	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() != 3)
	{
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}

	if (organism.contains("vai"))
	{
		QPixmap pixMap("vai.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (organism.contains("uai"))
	{
		QPixmap pixMap("uai.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
}

QSize ImageDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() == 1)
	{
		return QSize(32, 100);
	}

	return QStyledItemDelegate::sizeHint(option, index);
}
