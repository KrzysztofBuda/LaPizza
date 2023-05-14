//databasemanager.cpp

#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QDir>


DatabaseManager::DatabaseManager()
{
}

bool DatabaseManager::openDatabase()
{
    QString lokalizacjadb = "D:/telekomunikacja/Semestry/Moje/semestr 6/Programowanie Obiektowe/Projekt/LaPizza-main";

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

    qDebug() << "Zapytanie tworzenia tabeli:" << createTableQuery;

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

    qDebug() << "Przed wykonaniem zapytania INSERT:" << query.lastQuery();

    if (!query.exec()) {
        qDebug() << "Błąd zapytania do bazy danych:" << query.lastError().text();
        return false;
    }

    qDebug() << "Zapytanie INSERT wykonane poprawnie";

    return true;
}


void DatabaseManager::closeDatabase()
{
    m_database.close();
}

QSqlDatabase DatabaseManager::m_database;
