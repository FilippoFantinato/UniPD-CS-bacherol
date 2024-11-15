//
// Created by filippofantinato on 18/05/20.
//

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        setFixedSize(200, 200);

        QPushButton *quit = new QPushButton(tr("Quit"), this);

        connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    }
};



#endif //MYWIDGET_MYWIDGET_H
