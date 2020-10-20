#ifndef COMPLETER_H
#define COMPLETER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCompleter>

#include <iostream>

using namespace std;

class Completer : public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout *layout;
	QLineEdit *lineEdit;

	void addCompleter();

public:
	Completer(QWidget *parent = nullptr);
	~Completer();

private slots:
	void changeText(const QString&);
	void returnPressed();
};
#endif // COMPLETER_H
