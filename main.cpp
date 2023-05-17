//main.cpp

#include "mainwindow.h"
#include <QApplication>
#include <fstream>
#include <cstdlib>
#include <QDebug>
#include <iostream>
#include "pizza.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
