//
// Created by filippofantinato on 19/05/20.
//

#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QWidget>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QSlider>

class LCDRange : public QWidget
{
    Q_OBJECT;

private:
    QSlider *slider;

public:
    LCDRange(QWidget *parent = nullptr);

    int value() const;

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);
};


#endif //SLIDERS_LCDRANGE_H
