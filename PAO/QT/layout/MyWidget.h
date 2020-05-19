//
// Created by filippofantinato on 18/05/20.
//

#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QLCDNumber>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

class MyWidget : public QWidget
{
public:

    MyWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        setFixedSize(200, 200);

        QPushButton *quit = new QPushButton(tr("Quit"), this);
        connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

        QLCDNumber *lcd = new QLCDNumber(2); // 2 cifre
        lcd->setSegmentStyle(QLCDNumber::Filled);

        QSlider *slider = new QSlider(Qt::Horizontal, this);
        slider->setRange(0, 100);
        slider->setValue(0);
        connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(lcd);
        layout->addWidget(slider);
        layout->addWidget(quit);

        setLayout(layout);
    }
};



#endif //MYWIDGET_MYWIDGET_H
