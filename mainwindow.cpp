#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "Pizza.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ustawienie pierwszego okna
    ui->stackedWidget->setCurrentWidget(ui->pierwszeOkno);
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
    Zamowienie a;
    a.dodawanie_skladnikow();
}


void MainWindow::on_pushButton_9_clicked()
{
    Zamowienie a;
    a.dodawanie();
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
    Zamowienie a;
    a.usuwanie();
}

