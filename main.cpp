#include "mainwindow.h"
#include <QApplication>
#include <fstream>
#include <cstdlib>
#include <QDebug>
#include <sqlite3.h>
#include <iostream>
#include "Pizza.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Pizza margherita;
    margherita.cena = 20,00;
    margherita.id = 1;
    margherita.nazwa = "Margherita";

    Pizza capriciosa;
    capriciosa.cena = 22,50;
    capriciosa.id = 2;
    capriciosa.nazwa = "Capriciosa";

    Pizza pepperoni;
    pepperoni.cena = 23,00;
    pepperoni.id = 3;
    pepperoni.nazwa = "Pepperoni";

    Pizza hawajska;
    hawajska.cena = 24,50;
    hawajska.id = 4;
    hawajska.nazwa = "Hawajska";

    Pizza vege;
    vege.cena = 28,00;
    vege.id = 5;
    vege.nazwa = "Vege";

    return a.exec();
}
