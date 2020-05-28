#include <iostream>

#include <QApplication>

#include "tictactoe.h"
#include "model.h"
#include "controller.h"

using std::cout, std::endl;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Model m;
	Controller c(&m);
	TicTacToe w(&c);
	c.setView(&w);
	w.show();
	return a.exec();
}
