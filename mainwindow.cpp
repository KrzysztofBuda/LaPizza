//mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "pizza.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>

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
    Zamowienie a;
    a.dodawanie_skladnikow();
}


void MainWindow::on_pushButton_9_clicked()
{
    int id=1;
    Pizza p1;
    double price = p1.cenaPizzy(id);
    string namee = p1.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
    qDebug() << price;
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->usuwanie);
}


void MainWindow::on_pushButton_7_clicked()
{
    Zamowienie a;
    a.anulowanie();
}


void MainWindow::on_wrocButton3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Podsumowanie);
}


void MainWindow::on_pushButton_8_clicked()
{

}


void MainWindow::on_pushButton_12_clicked()
{
    int id=4;
    Pizza p4;
    double price = p4.cenaPizzy(id);
    string namee = p4.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
    qDebug() << price;
}

void MainWindow::on_pushButton_4_clicked()
{
    DatabaseManager d1;
    d1.openDatabase();

    qDebug() << "Przycisk został kliknięty.";

    // Tworzenie tabeli zamówień, jeśli nie istnieje
    QSqlQuery createTableQuery;
    createTableQuery.prepare("CREATE TABLE IF NOT EXISTS zamowienia (numer INTEGER PRIMARY KEY AUTOINCREMENT, pozycje TEXT)");
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

        // Zapisywanie pozycji z listy zamówień
        QStringList pozycjeZamowienia;
        for (int i = 0; i < listaZamowienWidget->count(); i++) {
            pozycjeZamowienia.append(listaZamowienWidget->item(i)->text());
        }
        QString pozycje = pozycjeZamowienia.join(", ");
        qDebug() << pozycje;
        // Wstawianie danych do tabeli zamówień
        QSqlQuery insertDataQuery;
        insertDataQuery.prepare("INSERT INTO zamowienia (numer, pozycje) VALUES (:numer, :pozycje)");
        insertDataQuery.bindValue(":numer", numerZamowienia);
        insertDataQuery.bindValue(":pozycje", pozycje);
        if (insertDataQuery.exec()) {
            qDebug() << "Dane zostały zapisane w tabeli zamowienia";
        } else {
            qDebug() << "Błąd zapisywania danych w tabeli zamowienia:" << insertDataQuery.lastError().text();
        }
    } else {
        qDebug() << "Błąd pobierania maksymalnego numeru zamówienia:" << getMaxNumerQuery.lastError().text();
    }

    d1.closeDatabase();
}


void MainWindow::on_pushButton_10_clicked()
{
    int id=2;
    Pizza p2;
    double price = p2.cenaPizzy(id);
    string namee = p2.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
    qDebug() << price;
}


void MainWindow::on_pushButton_11_clicked()
{
    int id=3;
    Pizza p3;
    double price = p3.cenaPizzy(id);
    string namee = p3.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
    qDebug() << price;
}


void MainWindow::on_pushButton_13_clicked()
{
    int id=5;
    Pizza p5;
    double price = p5.cenaPizzy(id);
    string namee = p5.nazwaPizzy(id);
    listaZamowienWidget->addItem(QString::fromStdString(namee));
    qDebug() << price;
}

