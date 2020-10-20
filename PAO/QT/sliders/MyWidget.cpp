//
// Created by filippofantinato on 19/05/20.
//

#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
{
    QPushButton *quit = new QPushButton("quit");
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QGridLayout *gridLayout = new QGridLayout;

    LCDRange *previousRange = nullptr;

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            LCDRange *lcdRange = new LCDRange;

            gridLayout->addWidget(lcdRange, i, j);

            if(previousRange)
            {
                connect(lcdRange, SIGNAL(valueChanged(int)), previousRange, SLOT(setValue(int)));
            }
            previousRange = lcdRange;
        }
    }

    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    vBoxLayout->addWidget(quit);
    vBoxLayout->addLayout(gridLayout);

    setLayout(vBoxLayout);
}
