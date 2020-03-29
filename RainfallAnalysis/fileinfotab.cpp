#include "fileinfotab.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>
#include "mainform.h"
#include "station.h"
#include <QtCharts>


FileInfoTab::FileInfoTab(Station *stat, QFileInfo fileInfo, QWidget *parent): QWidget(parent)
{
    station = stat;
    //station->setParent(this);
    fileNameLabel = new QLabel(tr("File Name:"));
    fileNameEdit = new QLineEdit();
    fileNameEdit->setText(fileInfo.fileName());

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(fileNameLabel);
    mainLayout->addWidget(fileNameEdit);

    QBarSet *set = new QBarSet("Average monthly rainfall");

    //QList<double> rain = station->getMonthlyAverages();

    for(int i = 0; i < 12; i++)
    {
        set->append(i);
    }

    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();
    series->append(set);
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sept" << "Oct" << "Nov" << "Dec";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,200);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addStretch(1);
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
}

