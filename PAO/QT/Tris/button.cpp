#include "button.h"

Button::Button(u_int x, u_int y, QWidget *parent) : QPushButton(parent), x(x), y(y)
{
	connect(this, SIGNAL(clicked()), this, SLOT(cellEmitter()));
}

void Button::cellEmitter()
{
	emit clickedCell(x, y);
}
