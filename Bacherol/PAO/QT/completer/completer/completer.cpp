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

	lineEdit = new QLineEdit(this);

	QCompleter *completer = new QCompleter(wordList);
	completer->setCaseSensitivity(Qt::CaseInsensitive);
	lineEdit->setCompleter(completer);

	completer->setCompletionRole(QCompleter::CompletionMode::PopupCompletion);

	layout->addWidget(lineEdit);

	connect(lineEdit, &QLineEdit::textChanged, this, &Completer::changeText);
	connect(lineEdit, &QLineEdit::returnPressed, this, &Completer::returnPressed);
}

Completer::~Completer()
{

}

void Completer::changeText(const QString &s)
{
	cout << "Change text row:" << lineEdit->completer()->currentRow() << endl;
}

void Completer::returnPressed()
{
	cout << "Return pressed row: " << lineEdit->completer()->currentRow() << endl;
	cout << "Return pressed text: " << lineEdit->text().toStdString() << endl;
}
