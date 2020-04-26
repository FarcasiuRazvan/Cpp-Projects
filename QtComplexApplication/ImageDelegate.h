#pragma once
#include <QStyledItemDelegate>

class ImageDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ImageDelegate(QWidget *parent = 0);

	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};
