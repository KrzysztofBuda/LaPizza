//mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "pizza.h"
#include <QIntValidator>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QLineEdit>
#include <ctime>
#include <sstream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Utwórz instancję DatabaseManager
    m_dbManager = new DatabaseManager();

    // Ustawienie pierwszego okna
    ui->stackedWidget->setCurrentWidget(ui->pierwszeOkno);

    // Otwarcie bazy danych
    if (!m_dbManager->openDatabase())
    {
        qDebug() << "Błąd otwarcia bazy danych";
        // Obsługa błędu otwarcia bazy danych
    }

    // Tworzenie tabeli
    if (!m_dbManager->createTable())
    {
        qDebug() << "Błąd tworzenia tabeli";
        // Obsługa błędu tworzenia tabeli
    }

    listaZamowienWidget = ui->listaZamowienWidget;

}

MainWindow::~MainWindow()
{
    delete ui;

    m_dbManager->closeDatabase();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stanZamowienia);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);
}

void MainWindow::on_wrocButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pierwszeOkno);
}


void MainWindow::on_wrocButton2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pierwszeOkno);
}

void MainWindow::on_podsumowanieButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Podsumowanie);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->menu);
}


void MainWindow::on_pushButton_6_clicked()
{
    int id = (ui->comboBox->currentIndex()) + 1;
    //qDebug() << id;
    int amount = ui->lineEdit->text().toInt();
    DatabaseManager a;
    a.openDatabase();
    a.updateIngredients(id, amount);
    a.closeDatabase();
}


void MainWindow::on_pushButton_9_clicked()
{
    int id=1;
    Pizza p1;
    string namee = p1.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
}


void MainWindow::on_pushButton_3_clicked()
{
    //usuwanie pozycji z zamówienia
    QListWidgetItem* selectedItem = listaZamowienWidget->currentItem();
    if (selectedItem != nullptr) {
        int row = listaZamowienWidget->row(selectedItem);
        listaZamowienWidget->takeItem(row);
        delete selectedItem;
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    listaZamowienWidget->clear();
}


void MainWindow::on_wrocButton3_clicked()
{

}


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Podsumowanie);
}


void MainWindow::on_pushButton_12_clicked()
{
    int id=4;
    Pizza p4;
    string namee = p4.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Platnosc);
}


void MainWindow::on_pushButton_10_clicked()
{
    int id=2;
    Pizza p2;
    string namee = p2.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
}


void MainWindow::on_pushButton_11_clicked()
{
    int id=3;
    Pizza p3;
    string namee = p3.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
}


void MainWindow::on_pushButton_13_clicked()
{
    int id=5;
    Pizza p5;
    string namee = p5.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    QLineEdit *lineEdit = ui->lineEdit;
    QIntValidator *validator = new QIntValidator(-999, 999, lineEdit);
    lineEdit->setValidator(validator);
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->odbior);
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->platnosc_online);
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Platnosc);
}


void MainWindow::on_pushButton_17_clicked()
{
    //przy odbiorze
    QString metoda_platnosci = "przy odbiorze";
    DatabaseManager db;
    Pizza pizza;
    Zamowienie zam;
    db.openDatabase();

    // Tworzenie tabeli zamówień, jeśli nie istnieje
    QSqlQuery createTableQuery;
    createTableQuery.prepare("CREATE TABLE IF NOT EXISTS zamowienia (numer INTEGER PRIMARY KEY AUTOINCREMENT, pozycje TEXT, wartosc NUMERIC, data_zamowienia TEXT, platnosc TEXT)");
    if (createTableQuery.exec()) {
        qDebug() << "Tabela została utworzona: zamowienia";
    } else {
        qDebug() << "Błąd tworzenia tabeli:" << createTableQuery.lastError().text();
    }

    // Pobieranie aktualnego numeru zamówienia
    QSqlQuery getMaxNumerQuery;
    getMaxNumerQuery.prepare("SELECT MAX(numer) FROM zamowienia");
    if (getMaxNumerQuery.exec() && getMaxNumerQuery.next()) {
        int numerZamowienia = getMaxNumerQuery.value(0).toInt() + 1;

        QStringList pozycjeZamowienia;
        for (int i = 0; i < listaZamowienWidget->count(); i++) {
            pozycjeZamowienia.append(listaZamowienWidget->item(i)->text());
        }
        //sprawdzenie czy jest wystarczająca ilosc składników do złożenia zamówienia
        if(pizza.countIngredientByName(pozycjeZamowienia)==true)
        {
            QString pozycje = pozycjeZamowienia.join(", ");

            //obliczenie kwoty zamówienia
            double wartosc_zamowienia = zam.oblicz_kwote(pozycjeZamowienia);
            //qDebug() << wartosc_zamowienia<<"Wartosc zamowienia";

            //dodanie daty i godziny do zamówienia
            std::time_t czas = std::time(nullptr);
            std::tm* czasInfo = std::localtime(&czas);

            int rok = czasInfo->tm_year + 1900;
            int miesiac = czasInfo->tm_mon + 1;
            int dzien = czasInfo->tm_mday;
            int godzina = czasInfo->tm_hour;
            int minuta = czasInfo->tm_min;
            std::ostringstream ss;
            ss << dzien << "." << miesiac << "." << rok << " " << godzina << ":" << minuta;
            QString data_zamowienia = QString::fromStdString(ss.str());

            //aktualizacja składników w bazie danych oraz dodanie zamówienia do bazy danych
            zam.updateIngredientsWhenOrder(pozycjeZamowienia);
            db.openDatabase();
            QSqlQuery insertDataQuery;
            insertDataQuery.prepare("INSERT INTO zamowienia (numer, pozycje, wartosc, data_zamowienia, platnosc) VALUES (:numer, :pozycje, :wartosc, :data_zamowienia, :platnosc)");
            insertDataQuery.bindValue(":numer", numerZamowienia);
            insertDataQuery.bindValue(":pozycje", pozycje);
            insertDataQuery.bindValue(":wartosc", wartosc_zamowienia);
            insertDataQuery.bindValue(":data_zamowienia", data_zamowienia);
            insertDataQuery.bindValue(":platnosc", metoda_platnosci);
            if (insertDataQuery.exec()) {
                qDebug() << "Dane zostały zapisane w tabeli zamowienia";
                //czyszczenie listy zamówień
                listaZamowienWidget->clear();;
            } else {
                qDebug() << "Błąd zapisywania danych w tabeli zamowienia:" << insertDataQuery.lastError().text();
            }
        }
        else
        {
            qDebug()<<"Nie ma odpowiedniej ilość składników do złożenia zamówienia";
            QMessageBox::information(nullptr, "Uwaga!", "Nie ma odpowiedniej ilości składników do złożenia zamówienia!\nZadzwoń do obsługi aby dowiedzieć się więcej");
            ui->stackedWidget->setCurrentWidget(ui->odbior);
        }
    } else {
        qDebug() << "Błąd pobierania maksymalnego numeru zamówienia:" << getMaxNumerQuery.lastError().text();
    }

    db.closeDatabase();
    QMessageBox::information(nullptr, "Gotowe!", "Zamówienie złożone");
}


void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->platnosc_online);
}


void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->odbior);
}


void MainWindow::on_pushButton_20_clicked()
{
    //przekieruj do banku i wróć
    QString metoda_platnosci = "z góry";
    DatabaseManager db;
    Pizza pizza;
    Zamowienie zam;
    db.openDatabase();

    // Tworzenie tabeli zamówień, jeśli nie istnieje
    QSqlQuery createTableQuery;
    createTableQuery.prepare("CREATE TABLE IF NOT EXISTS zamowienia (numer INTEGER PRIMARY KEY AUTOINCREMENT, pozycje TEXT, wartosc NUMERIC, data_zamowienia TEXT, platnosc TEXT)");
    if (createTableQuery.exec()) {
        qDebug() << "Tabela została utworzona: zamowienia";
    } else {
        qDebug() << "Błąd tworzenia tabeli:" << createTableQuery.lastError().text();
    }

    // Pobieranie aktualnego numeru zamówienia
    QSqlQuery getMaxNumerQuery;
    getMaxNumerQuery.prepare("SELECT MAX(numer) FROM zamowienia");
    if (getMaxNumerQuery.exec() && getMaxNumerQuery.next()) {
        int numerZamowienia = getMaxNumerQuery.value(0).toInt() + 1;

        QStringList pozycjeZamowienia;
        for (int i = 0; i < listaZamowienWidget->count(); i++) {
            pozycjeZamowienia.append(listaZamowienWidget->item(i)->text());
        }
        //sprawdzenie czy jest wystarczająca ilosc składników do złożenia zamówienia
        if(pizza.countIngredientByName(pozycjeZamowienia)==true)
        {
            QString pozycje = pozycjeZamowienia.join(", ");

            //obliczenie kwoty zamówienia
            double wartosc_zamowienia = zam.oblicz_kwote(pozycjeZamowienia);
            //qDebug() << wartosc_zamowienia<<"Wartosc zamowienia";

            //dodanie daty i godziny do zamówienia
            std::time_t czas = std::time(nullptr);
            std::tm* czasInfo = std::localtime(&czas);

            int rok = czasInfo->tm_year + 1900;
            int miesiac = czasInfo->tm_mon + 1;
            int dzien = czasInfo->tm_mday;
            int godzina = czasInfo->tm_hour;
            int minuta = czasInfo->tm_min;
            std::ostringstream ss;
            ss << dzien << "." << miesiac << "." << rok << " " << godzina << ":" << minuta;
            QString data_zamowienia = QString::fromStdString(ss.str());

            //aktualizacja składników w bazie danych oraz dodanie zamówienia do bazy danych
            zam.updateIngredientsWhenOrder(pozycjeZamowienia);
            db.openDatabase();
            QSqlQuery insertDataQuery;
            insertDataQuery.prepare("INSERT INTO zamowienia (numer, pozycje, wartosc, data_zamowienia, platnosc) VALUES (:numer, :pozycje, :wartosc, :data_zamowienia, :platnosc)");
            insertDataQuery.bindValue(":numer", numerZamowienia);
            insertDataQuery.bindValue(":pozycje", pozycje);
            insertDataQuery.bindValue(":wartosc", wartosc_zamowienia);
            insertDataQuery.bindValue(":data_zamowienia", data_zamowienia);
            insertDataQuery.bindValue(":platnosc", metoda_platnosci);
            if (insertDataQuery.exec()) {
                qDebug() << "Dane zostały zapisane w tabeli zamowienia";
                //czyszczenie listy zamówień
                listaZamowienWidget->clear();;
            } else {
                qDebug() << "Błąd zapisywania danych w tabeli zamowienia:" << insertDataQuery.lastError().text();
            }
        }
        else
        {
            qDebug()<<"Nie ma odpowiedniej ilość składników do złożenia zamówienia";
            QMessageBox::information(nullptr, "Uwaga!", "Nie ma odpowiedniej ilości składników do złożenia zamówienia!\nZadzwoń do obsługi aby dowiedzieć się więcej");
            ui->stackedWidget->setCurrentWidget(ui->odbior);
        }
    } else {
        qDebug() << "Błąd pobierania maksymalnego numeru zamówienia:" << getMaxNumerQuery.lastError().text();
    }

    db.closeDatabase();
    //wróć do głównej strony + komunikat
    QMessageBox::information(nullptr, "Gotowe!", "Zamówienie złożone");
    ui->stackedWidget->setCurrentWidget(ui->pierwszeOkno);
}


void MainWindow::on_magazynButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->magazynWindow);
    updateStanMagazynuList();
}


void MainWindow::on_statystykiButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->statystykiWindow);
}

void MainWindow::updateStanMagazynuList()
{
    // Wyczyść listę przed aktualizacją
    ui->stanMagazynuList->clear();

    // Pobierz dane z bazy danych
    DatabaseManager db;
    db.openDatabase();

    // Pobierz listę składników i ich stany
    QSqlQuery query("SELECT nazwa, ilosc FROM skladniki");
    while (query.next()) {
        QString skladnik = query.value(0).toString();
        int stan = query.value(1).toInt();

        // Wyświetl składnik i stan w QListWidget
        QString itemText = skladnik + " - Stan: " + QString::number(stan);
        QListWidgetItem* item = new QListWidgetItem(itemText);
        ui->stanMagazynuList->addItem(item);
    }

    db.closeDatabase();
}

void MainWindow::on_wrocButton_2_clicked()
{
   ui->stackedWidget->setCurrentWidget(ui->stanZamowienia);
}


void MainWindow::on_wrocButton2_2_clicked()
{
   ui->stackedWidget->setCurrentWidget(ui->stanZamowienia);
}

