#ifndef STATYSTYKIWINDOW_H
#define STATYSTYKIWINDOW_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>

QT_BEGIN_NAMESPACE
namespace Ui { class StatystykiWindow; }
QT_END_NAMESPACE

class StatystykiWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StatystykiWindow(QWidget *parent = nullptr);
    ~StatystykiWindow();

private:
    Ui::StatystykiWindow *ui;
    QChart *chart;
    QLineSeries *series;
    QChartView *chartView;
};

#endif // STATYSTYKIWINDOW_H
