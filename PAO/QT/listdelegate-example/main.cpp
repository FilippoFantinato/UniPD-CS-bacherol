#include "mainwindow.h"

#include <QApplication>
#include <QTableWidget>
#include <QListView>
#include <QListWidget>
#include <QAbstractGraphicsShapeItem>

#include "listdelegate.h"

void populateTableWidget(QTableWidget *tableWidget);

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

//	QTableWidget tableWidget(10000, 4);
	QListWidget *myListWidget = new QListWidget();

	myListWidget->setItemDelegate(new ListDelegate(myListWidget));
	QListWidgetItem *item = new QListWidgetItem();
	item->setData(Qt::DisplayRole, "Title");
	item->setData(Qt::UserRole + 1, "Description");
	myListWidget->addItem(item);


//	listView->setItemWi(0, new QList("Ciao"));
//	tableWidget.setItemDelegate(new StarDelegate);
//	tableWidget.setEditTriggers(QAbstractItemView::DoubleClicked
//								| QAbstractItemView::SelectedClicked);
//	tableWidget.setSelectionBehavior(QAbstractItemView::SelectRows);
//	tableWidget.setHorizontalHeaderLabels({"Title", "Genre", "Artist", "Rating"});

//	populateTableWidget(&tableWidget);

//	tableWidget.resizeColumnsToContents();
//	tableWidget.resize(500, 300);
//	tableWidget.show();
	myListWidget->show();

	return app.exec();
}

//void populateTableWidget(QTableWidget *tableWidget)
//{
//	static constexpr struct {
//		const char *title;
//		const char *genre;
//		const char *artist;
//		int rating;
//	} staticData[] = {
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ "Mass in B-Minor", "Baroque", "J.S. Bach", 5 },
//	{ nullptr, nullptr, nullptr, 0 }
//	};

//	for (int row = 0; staticData[row].title != nullptr; ++row) {
//		QTableWidgetItem *item0 = new QTableWidgetItem(staticData[row].title);
//		QTableWidgetItem *item1 = new QTableWidgetItem(staticData[row].genre);
//		QTableWidgetItem *item2 = new QTableWidgetItem(staticData[row].artist);
//		QTableWidgetItem *item3 = new QTableWidgetItem;
//		item3->setData(0,
//					   QVariant::fromValue(StarRating(staticData[row].rating)));

//		tableWidget->setItem(row, 0, item0);
//		tableWidget->setItem(row, 1, item1);
//		tableWidget->setItem(row, 2, item2);
//		tableWidget->setItem(row, 3, item3);
//	}
//}
