/*
 *
 * Copyright (c) 2015 Talha ORAK<talhaorak at gmail.com>
 *                    talhaorak.net
 *
 */

#include "MainWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    return a.exec();
}
