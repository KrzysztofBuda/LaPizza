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
bool Pizza::countIngredientByName(QStringList name) {     //sprawdza czy w jest odpowiednia ilość składników w bazie do złożenia zamówienia

    DatabaseManager db;
    db.openDatabase();
    int sos = db.checkIngredients(1);
    int ser = db.checkIngredients(2);
    int szynka = db.checkIngredients(3);
    int oregano = db.checkIngredients(4);
    int pepperoni = db.checkIngredients(5);
    int ananas = db.checkIngredients(6);
    int weganskiSer = db.checkIngredients(7);
    int weganskaSzynka = db.checkIngredients(8);

    for (QStringList::iterator it = name.begin(); it != name.end(); ++it)
    {
        const QString &nejm = *it;
        int id = db.getPizzaId(nejm);
        switch(id){
            case 1:
                sos -= 1;
                ser -= 1;
                oregano -= 1;
                break;
            case 2:
                sos -= 1;
                ser -= 1;
                oregano -= 1;
                szynka -= 1;
                break;
            case 3:
                sos -= 1;
                ser -= 1;
                oregano -= 1;
                pepperoni -= 1;
                break;
            case 4:
                sos -= 1;
                ser -= 1;
                szynka -= 1;
                ananas -= 1;
                break;
            case 5:
                sos -= 1;
                weganskaSzynka -= 1;
                weganskiSer -= 1;
                break;
        }
    }
    db.closeDatabase();
    if(sos<0 || ser<0 || szynka<0 || oregano<0 || pepperoni<0 || ananas<0 || weganskiSer<0 || weganskaSzynka<0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


void Zamowienie::oblicz_kwote() {

}

void Zamowienie::updateIngredientsWhenOrder(QStringList name) {
    DatabaseManager db;
    db.openDatabase();
    int sos = 0;
    int ser = 0;
    int szynka = 0;
    int oregano = 0;
    int pepperoni = 0;
    int ananas = 0;
    int weganskiSer = 0;
    int weganskaSzynka = 0;

    for (QStringList::iterator it = name.begin(); it != name.end(); ++it)
    {
        const QString &nejm = *it;
        int id = db.getPizzaId(nejm);
        switch(id){
        case 1:
                sos -= 1;
                ser -= 1;
                oregano -= 1;
                break;
        case 2:
                sos -= 1;
                ser -= 1;
                oregano -= 1;
                szynka -= 1;
                break;
        case 3:
                sos -= 1;
                ser -= 1;
                oregano -= 1;
                pepperoni -= 1;
                break;
        case 4:
                sos -= 1;
                ser -= 1;
                szynka -= 1;
                ananas -= 1;
                break;
        case 5:
                sos -= 1;
                weganskaSzynka -= 1;
                weganskiSer -= 1;
                break;
        }
    }
    db.updateIngredients(1,sos);
    db.updateIngredients(2,ser);
    db.updateIngredients(3,szynka);
    db.updateIngredients(4,oregano);
    db.updateIngredients(5,pepperoni);
    db.updateIngredients(6,ananas);
    db.updateIngredients(7,weganskiSer);
    db.updateIngredients(8,weganskaSzynka);
    qDebug() << "Aktualizacja składników w bazie wykonana poprawnie";
}

