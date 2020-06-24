#include "completer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Completer w;
	w.show();
	return a.exec();
}
