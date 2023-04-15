#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sqlite3.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    ui->textEdit->setText("Ala ma kota");



    /*sqlite3* db;
    int rc = sqlite3_open("/Users/bartek/Downloads/LaPizza-main/mydatabase.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Nie udało się otworzyć bazy danych: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
    }

    const char* sql_create_table = "CREATE TABLE IF NOT EXISTS mytable (id INTEGER PRIMARY KEY, nazwa_pizzy TEXT, cena NUMERIC)";
    rc = sqlite3_exec(db, sql_create_table, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Nie udało się utworzyć tabeli: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
    }

    const char* sql_insert = "INSERT INTO mytable (nazwa_pizzy, cena) VALUES ('Wege', 28.00)";
    rc = sqlite3_exec(db, sql_insert, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Nie udało się dodać rekordu: " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
    }

    sqlite3_close(db);
    std::cout << "Rekord został dodany do bazy danych" << std::endl;
*/
}

