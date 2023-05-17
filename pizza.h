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

    string nazwaPizzy(int id);
    double cenaPizzy(int id);
};

class Zamowienie{
public:
    double cena;
    int nr_zamówienia;
    double wartosc;

    void dodawanie();

    void usuwanie();

    void anulowanie();

    void oblicz_kwote();

    void dodawanie_skladnikow();
};

class Klient{
public:
    string imie;
    int nr_telefonu;
    string adres;

    void platnosc();

    void skladanie_zamowienia();
};

class Platnosc{
public:
    int platnosc_nr;
    double suma;
    string rodzaj_platnosci;

    void nr_platnosci();

    void platnosc_info();

    void sumowanie();
};

class Platnosc_online{
public:
    void zaplac();
};

#endif // PIZZA_H
