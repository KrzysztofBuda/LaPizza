//databasemanager.cpp

#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QDir>

using namespace std;

DatabaseManager::DatabaseManager()
{
}

bool DatabaseManager::openDatabase()
{
    QString lokalizacjadb = "/Users/bartek/Documents/Programowanie obiektowe/LaPizza-main";

    QString appFilePath = QCoreApplication::applicationFilePath();
    QString appDirPath = QFileInfo(appFilePath).absoluteDir().path();
    QString databasePath = QDir(appDirPath).filePath(lokalizacjadb +"/mydatabaseee.db");

    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(databasePath);

    if (!m_database.open()) {
        qDebug() << "Nie można otworzyć bazy danych";
        return false;
    }
    qDebug() << "Baza danych otwarta";
    return true;
}

bool DatabaseManager::createTable()
{
    QSqlQuery query;
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS pizza ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "nazwa TEXT)";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Błąd tworzenia tabeli:" << query.lastError().text();
        return false;
    }

    qDebug() << "Tabela została utworzona: pizza";

    // Odczyt danych z tabeli pizza i wyświetlenie ich na konsoli
    QSqlQuery selectQuery("SELECT * FROM pizza");
    while (selectQuery.next()) {
        int id = selectQuery.value(0).toInt();
        QString nazwa = selectQuery.value(1).toString();
        qDebug() << "ID:" << id << "Nazwa:" << nazwa;
    }

    return true;
}


bool DatabaseManager::insertData(const QString& data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO pizza (nazwa) VALUES (?)");
    query.addBindValue(data);

    if (!query.exec()) {
        qDebug() << "Błąd zapytania do bazy danych:" << query.lastError().text();
        return false;
    }

    qDebug() << "Zapytanie INSERT wykonane poprawnie";

    return true;
}

string DatabaseManager::getPizzaName(int id)
{
    string nazwa;

    QSqlQuery query;
    query.prepare("SELECT nazwa FROM pizza WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        nazwa = query.value(0).toString().toStdString();
    } else {
        qDebug() << "Błąd zapytania do bazy danych:" << query.lastError().text();
    }

    return nazwa;
}

double DatabaseManager::getPizzaPrice(int id)
{
    double price = 0.0;

    QSqlQuery query;
    query.prepare("SELECT cena FROM pizza WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
            price = query.value(0).toDouble();
        } else if (query.lastError().isValid()) {
            qDebug() << "Błąd zapytania do bazy danych:" << query.lastError().text();
        } else {
            qDebug() << "Brak pizzy o podanym identyfikatorze:" << id;
        }
    return price;
}

int DatabaseManager::getPizzaId(QString name) {
    int id = -1;

    QSqlQuery query;
    query.prepare("SELECT id FROM pizza Where nazwa = ?");
    query.addBindValue(name);

    if (query.exec() && query.next()) {
            id = query.value(0).toDouble();
        } else if (query.lastError().isValid()) {
            qDebug() << "Błąd zapytania do bazy danych:" << query.lastError().text();
        } else {
            qDebug() << "Brak pizzy o podanej nazwie:" << name;
        }
        //qDebug() << id;
    return id;
}

bool DatabaseManager::updateIngredients(int id, int amount)
{
    QSqlQuery query;
    query.prepare("UPDATE skladniki SET ilosc = ilosc + :amount WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":amount", amount);

    if (!query.exec()) {
        qDebug() << "Błąd zapytania do bazy danych:" << query.lastError().text();
        return false;
    }
    //qDebug() << "Zapytanie Uppdate wykonane poprawnie";
    return true;
}

int DatabaseManager::checkIngredients(int id)
{
    int ilosc = 0;
    QSqlQuery query;
    query.prepare("SELECT ilosc FROM skladniki WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        ilosc = query.value(0).toInt();
        qDebug() << "Ilość składnika o id" << id << ":" << ilosc;
    }
    else {
        qDebug() << "Błąd zapytania do bazy danych:" << query.lastError().text();
    }
    return ilosc;
}


void DatabaseManager::closeDatabase()
{
    m_database.close();
}

QSqlDatabase DatabaseManager::m_database;
