#include "statystykiwindow.h"
#include "ui_statystykiwindow.h"

StatystykiWindow::StatystykiWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatystykiWindow)
{
    ui->setupUi(this);

    // Tworzenie wykresu i serii
    chart = new QChart();
    series = new QLineSeries();
    chart->addSeries(series);
    chart->legend()->hide();
    chart->setTitle("Statystyki");

    // Tworzenie widoku wykresu i ustawienie go jako główny widżet
    chartView = new QChartView(chart);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    setLayout(layout);
}

StatystykiWindow::~StatystykiWindow()
{
    delete ui;
}
