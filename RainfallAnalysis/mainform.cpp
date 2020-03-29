#include "mainform.h"
#include "fileinfotab.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>

MainForm::MainForm(QWidget *parent): QDialog(parent)
{
    selectFile = new QPushButton(tr("Select file"));
    selectFile->setParent(this);
    connect(selectFile, SIGNAL (released()), this, SLOT (attemptStationLoad()));
}

bool MainForm::fileSuccess(QString &filePath)
{
    filePath = QFileDialog::getOpenFileName(this, "Get Any File");
    return (!filePath.isEmpty());
}

bool MainForm::readStationData(QString filePath, Station *stat)
{
    QFile inputFile(filePath);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        QString line = in.readLine();
           while (line.left(4) != "DATE" && !in.atEnd())
           {
              qDebug()<<line<<'\n';
               line = in.readLine();
           }

           QString date;
           double rainfall;
           int qual;

           stat = new Station();

           while (!in.atEnd())
           {
               in >> date;
               in >> rainfall;
               in >> qual;
               DayRainRec rec;
               rec.day = QDate::fromString(date, "yyyyMMdd");
               rec.rain = rainfall;
               rec.qualCode = qual;
               stat->addRecord(rec);

               if(rec.qualCode == 1)
               {
                    stat->addDay(rec.day.month());
                    stat->addRain(rec.day.month(), rec.rain);
               }
           }

           inputFile.close();
           return true;
    }
    return false;
}

void MainForm::attemptStationLoad()
{
    Station* station;
    QString filepath;
    if(fileSuccess(filepath))
    {
        if(readStationData(filepath, station) && station)
        {
           tabWidget = new QTabWidget;
            FileInfoTab* graph = new FileInfoTab(station, QFileInfo(filepath));
            tabWidget->addTab(graph, tr("Station"));
            QVBoxLayout *mainLayout = new QVBoxLayout;
                mainLayout->addWidget(tabWidget);
                setLayout(mainLayout);
        }
    }
}
