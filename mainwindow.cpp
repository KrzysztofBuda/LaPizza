#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

