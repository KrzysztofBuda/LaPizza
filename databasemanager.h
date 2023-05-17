//databasemanager.h

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
using namespace std;


class DatabaseManager
{
public:
    DatabaseManager();

    bool openDatabase();
    bool createTable();
    bool insertData(const QString& data);
    void closeDatabase();
    string getPizzaName(int id);
    double getPizzaPrice(int id);

private:
    static QSqlDatabase m_database; // Przeniesiona deklaracja zmiennej m_database
};

#endif // DATABASEMANAGER_H
