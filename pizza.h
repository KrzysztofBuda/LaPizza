#ifndef PIZZA_H
#define PIZZA_H
#include <QString>
#include <iostream>
#include <cstdlib>
#include <sqlite3.h>
#include <QSqlQuery>
#include <QSqlError>

using namespace std;

class Pizza{
public:
    string nazwa;
    int id;
    double cena;
    int idPizzy(QString name);
    string nazwaPizzy(int id);
    double cenaPizzy(int id);
    bool countIngredientByName(QStringList name);
};

class Zamowienie{
public:
    double oblicz_kwote(QStringList name);
    void updateIngredientsWhenOrder(QStringList name);
};

#endif // PIZZA_H
