//mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <stdio.h>
#include <iostream>
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>

#include "databasemanager.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_2_clicked();

    void on_push_Button_clicked();

    void on_wroc_Button_clicked();

    void on_wroc_Button2_clicked();

    void on_podsumowanie_Button_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_lineEdit_textEdited();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_magazyn_Button_clicked();

    void on_statystyki_Button_clicked();

    void updateStanMagazynuList();

    void on_wrocButton_2_clicked();

    void on_wrocButton2_2_clicked();

    void statystykiDaneDoWykresu();

    void on_wrocButton2_3_clicked();

    void statystykiDaneDoWykresuOstatnie7();

    void on_Ostatnie7Dni_Button_clicked();

private:
    Ui::MainWindow *ui;
    DatabaseManager* m_dbManager;
    QList<QString> listaZamowien; // Lista zamówień
    QListWidget* listaZamowienWidget; // List Widget dla zamówień

    void generujWykres();
    QMap<QString, int> pobierzLiczbePizz();
    void generujWykresZamowienOstatnichDni();
    QMap<QString, int> pobierzLiczbePizzOstatnich();
};
#endif // MAINWINDOW_H
