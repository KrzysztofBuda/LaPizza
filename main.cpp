#include "mainwindow.h"
#include <QApplication>
#include <fstream>
#include <cstdlib>
#include <QtSql>
#include <QDebug>
#include <sqlite3.h>
#include <iostream>
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

    /*sqlite3* db;
    int rc = sqlite3_open("/Users/bartek/Downloads/LaPizza-main/mydatabase.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
        return 1;
    }

    const char* sql_create_table = "CREATE TABLE IF NOT EXISTS mytable (id INTEGER PRIMARY KEY, nazwa_pizzy TEXT, cena NUMERIC)";
    rc = sqlite3_exec(db, sql_create_table, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Nie udało się utworzyć tabeli: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
        return 1;
    }

    const char* sql_insert = "INSERT INTO mytable (nazwa_pizzy, cena) VALUES ('Pepperoni', 23.00)";
    rc = sqlite3_exec(db, sql_insert, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Nie udało się dodać rekordu: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    std::cout << "Rekord został dodany do bazy danych" << std::endl;
*/




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
