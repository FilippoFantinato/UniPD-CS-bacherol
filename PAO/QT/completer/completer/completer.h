#ifndef COMPLETER_H
#define COMPLETER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCompleter>

class Completer : public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout *layout;

	void addCompleter();

public:
	Completer(QWidget *parent = nullptr);
	~Completer();
};
#endif // COMPLETER_H
