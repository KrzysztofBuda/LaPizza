#include "pizza.h"
#include "databasemanager.h"


using namespace std;

string Pizza::nazwaPizzy(int id) {
    string name;
    DatabaseManager d1;
    d1.openDatabase();
    name = d1.getPizzaName(id);
    d1.closeDatabase();
    return name;
    }

double Pizza::cenaPizzy(int id) {
    double cena = 0.0;
    DatabaseManager d2;
    d2.openDatabase();
    cena = d2.getPizzaPrice(id);
    d2.closeDatabase();
    return cena;
    }

void Zamowienie::dodawanie() {
    wartosc =500;
    sqlite3* db;
    int rc = sqlite3_open("mydatabase.db", &db);
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

void Zamowienie::usuwanie() {
    sqlite3* db;
    int rc = sqlite3_open("mydatabase.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }

    const char* sql_insert = "DELETE FROM zamowienia WHERE id = 12";
    rc = sqlite3_exec(db, sql_insert, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Nie udało się usunąć rekordu: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }

    sqlite3_close(db);
    std::cout << "Rekord został usunięty z bazy danych" << std::endl;
}

void Zamowienie::oblicz_kwote() {

}
