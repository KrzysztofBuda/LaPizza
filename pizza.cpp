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

int Pizza::idPizzy(QString name) {
    int id=-1;
    DatabaseManager d3;
    d3.openDatabase();
    id = d3.getPizzaId(name);
    d3.closeDatabase();
    return id;
}
bool Pizza::countIngredients(string name) {
    DatabaseManager db;
    db.openDatabase();

    bool allIngredientsAvailable = true;

    if (name == "Margherita") {
        // sos, ser, oregano
        if (db.checkIngredients(1)) {
            db.updateIngredients(1, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(2)) {
            db.updateIngredients(2, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(4)) {
            db.updateIngredients(4, -1);
        } else {
            allIngredientsAvailable = false;
        }
    }
    else if (name == "Capriciosa") {
        // sos, ser, szynka, oregano
        if (db.checkIngredients(1)) {
            db.updateIngredients(1, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(2)) {
            db.updateIngredients(2, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(3)) {
            db.updateIngredients(3, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(4)) {
            db.updateIngredients(4, -1);
        } else {
            allIngredientsAvailable = false;
        }
    }
    else if (name == "Pepperoni") {
        // sos, ser, pepperoni, oregano
        if (db.checkIngredients(1)) {
            db.updateIngredients(1, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(2)) {
            db.updateIngredients(2, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(5)) {
            db.updateIngredients(5, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(4)) {
            db.updateIngredients(4, -1);
        } else {
            allIngredientsAvailable = false;
        }
    }
    else if (name == "Hawajska") {
        // sos, ser, szynka, ananas
        if (db.checkIngredients(1)) {
            db.updateIngredients(1, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(2)) {
            db.updateIngredients(2, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(3)) {
            db.updateIngredients(3, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(6)) {
            db.updateIngredients(6, -1);
        } else {
            allIngredientsAvailable = false;
        }
    }
    else if (name == "Vege") {
        // sos, wegański ser, wegańska szynka
        if (db.checkIngredients(1)) {
            db.updateIngredients(1, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(7)) {
            db.updateIngredients(7, -1);
        } else {
            allIngredientsAvailable = false;
        }
        if (db.checkIngredients(8)) {
            db.updateIngredients(8, -1);
        } else {
            allIngredientsAvailable = false;
        }
    }
    else {
        qDebug() << "Nie ma takiej pozycji w bazie";
        db.closeDatabase();
        return false;
    }

    db.closeDatabase();

    if (!allIngredientsAvailable) {
        qDebug() << "Niektóre składniki nie są dostępne";
        return false;
    }

    qDebug() << "Zaktualizowano składniki";
        return true;
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

void Zamowienie::updateIngredientsWhenOrder(QString name) {

}

