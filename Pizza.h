#ifndef PIZZA_H
#define PIZZA_H
#include <QString>
#include "sqlite3\sqlite3.h"
#include <iostream>
#include <cstdlib>

#endif // PIZZA_H

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
    double wartosc = 21;

    void dodawanie() {
        sqlite3* db;
        int rc = sqlite3_open("/Users/bartek/Downloads/LaPizza-main/mydatabase.db", &db);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        const char* sql_create_table = "CREATE TABLE IF NOT EXISTS zamowienia (id INTEGER PRIMARY KEY, cena NUMERIC)";
        rc = sqlite3_exec(db, sql_create_table, nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się utworzyć tabeli: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        string sql_insert = "INSERT INTO zamowienia (cena) VALUES (" + to_string(wartosc) + ")";
        const char* sql_query = sql_insert.c_str();
        rc = sqlite3_exec(db, sql_query, nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się dodać rekordu: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        sqlite3_close(db);
        std::cout << "Rekord został dodany do bazy danych" << std::endl;
    }

    void usuwanie() {
        sqlite3* db;
        int rc = sqlite3_open("/Users/bartek/Downloads/LaPizza-main/mydatabase.db", &db);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        const char* sql_insert = "DELETE FROM zamowienia WHERE id = 2";
        rc = sqlite3_exec(db, sql_insert, nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się usunąć rekordu: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        sqlite3_close(db);
        std::cout << "Rekord został usunięty z bazy danych" << std::endl;
    }

    void anulowanie() {
        sqlite3* db;
        int rc = sqlite3_open("/Users/bartek/Downloads/LaPizza-main/mydatabase.db", &db);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        const char* sql_insert = "DELETE FROM zamowienia";
        rc = sqlite3_exec(db, sql_insert, nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się dodać rekordu: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        sqlite3_close(db);
        std::cout << "Rekord został dodany do bazy danych" << std::endl;
    }

    void oblicz_kwote() {

    }

    void dodawanie_skladnikow() {
        sqlite3* db;
        int rc = sqlite3_open("/Users/bartek/Downloads/LaPizza-main/mydatabase.db", &db);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        const char* sql_create_table = "CREATE TABLE IF NOT EXISTS skladniki (id INTEGER PRIMARY KEY, nazwa_skladnika TEXT, ilosc INTEGER)";
        rc = sqlite3_exec(db, sql_create_table, nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się utworzyć tabeli: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        const char* sql_insert = "UPDATE skladniki SET ilosc = ilosc + 9 WHERE id=9";
        rc = sqlite3_exec(db, sql_insert, nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK) {
            std::cerr << "Nie udało się zaktualizować rekordu: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
        }

        sqlite3_close(db);
        std::cout << "Rekord został zaktualizowany w bazie danych" << std::endl;
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
