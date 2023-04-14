#include "mainwindow.h"
#include <QApplication>
#include <fstream>
#include <cstdlib>
#include <QtSql>
#include <QDebug>
#include "sqlite3/sqlite3.h"
using namespace std;

class Pizza{
public:
    string nazwa;
    int id;
    double cena;

    string nazwaPizzy() {
        return nazwa;
    }
    double cenaPizzy() {
        return cena;
    }
    int idPizzy() {
        return id;
    }
};

class Zamowienie{
public:
    double cena;
    int nr_zamówienia;

    void dodawanie() {

    }

    void usuwanie() {

    }

    void anulowanie() {

    }

    void oblicz_kwote() {

    }
};

class Klient{
public:
    string imie;
    int nr_telefonu;
    string adres;

    void płatność() {

    }

    void składanie_zamówienia() {

    }
};

class Platnosc{
public:
    int nr_platnosci;
    double suma;
    string rodzaj_płatności;

    int nr_płatności() {

    }

    void płatność_info(){

    }

    void sumowanie(){

    }
    };

class Platnosc_online{
public:
    void zaplac() {

    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/bartek/Downloads/LaPizza-main/pizzaBaza");
    db.open();
    if(db.isOpen())
    {
        qDebug() << "DB OPENED";
    }
    else
    {
        qDebug() << "DB NOT OPENED";
    }

    QSqlQuery q;
    QString data = "";
    q.exec("SELECT * FROM tb1");

    while(q.next()) {
        data += q.value(0).toString() + "-";
        data += q.value(1).toString() + "\n";
    }




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

    db.close();
    return a.exec();
}
