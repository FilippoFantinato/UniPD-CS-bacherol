#include "completer.h"

Completer::Completer(QWidget *parent)
	: QWidget(parent)
{
	layout = new QVBoxLayout(this);

	addCompleter();

	setLayout(layout);
}

void Completer::addCompleter()
{
	QStringList wordList;
	wordList << "alpha" << "omega" << "omicron" << "zeta";

	QLineEdit *lineEdit = new QLineEdit(this);

	QCompleter *completer = new QCompleter(wordList, this);
	completer->setCaseSensitivity(Qt::CaseInsensitive);
	lineEdit->setCompleter(completer);

	layout->addWidget(lineEdit);
}

Completer::~Completer()
{

}

