#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
	Q_OBJECT
private:
	u_int x, y;

private slots:
	void cellEmitter();


public:
	Button(u_int i, u_int j, QWidget *parent = nullptr);

signals:
	void clickedCell(unsigned int, unsigned int);

};

#endif // BUTTON_H
