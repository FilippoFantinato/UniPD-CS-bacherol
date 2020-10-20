//
// Created by filippofantinato on 19/05/20.
//

#include "LCDRange.h"

LCDRange::LCDRange(QWidget *parent) : QWidget(parent), slider(new QSlider(Qt::Horizontal))
{
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    slider->setRange(0, 100);
    slider->setValue(0);

    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

int LCDRange::value() const
{
    return slider->value();
}

void LCDRange::setValue(int value)
{
    slider->setValue(value);
}
