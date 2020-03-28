#include "mainform.h"
#include "fileinfotab.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>

MainForm::MainForm(QWidget *parent): QDialog(parent)
{
    station = nullptr;
    tabWidget = new QTabWidget();
    tabWidget->addTab(new FileInfoTab("fileInfo"), tr("File Info"));
    selectFile = new QPushButton(tr("Select file"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(selectFile);
    setLayout(mainLayout);//this sorts out parentage

    connect(selectFile, SIGNAL (released()), this, SLOT (attemptStationLoad()));

}

Station *MainForm::getStation()
{
    return station;
}


bool MainForm::fileSuccess(QString &filePath)
{
    filePath = QFileDialog::getOpenFileName(this, "Get Any File");
    return (!filePath.isEmpty());
}

bool MainForm::readStationData(QString filePath)
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

           while (!in.atEnd())
           {
               in >> date;
               in >> rainfall;
               in >> qual;
               DayRainRec rec;
               rec.day = QDate::fromString(date, "yyyyMMdd");
               rec.rain = rainfall;
               rec.qualCode = qual;
               station->addRecord(rec);

               if(rec.qualCode == 1)
               {
                    station->addDay(rec.day.month());
                    station->addRain(rec.day.month(), rec.rain);
               }
           }

           inputFile.close();
           return true;
    }
    return false;
}

void MainForm::attemptStationLoad()
{
    QString filepath;
    if(fileSuccess(filepath))
    {
        if (station) delete station;
        station = new Station(this);

        if(readStationData(filepath))
        {
            QString childName = "fileInfo";
            FileInfoTab* fileInfoTab = findChild<FileInfoTab*>("fileInfo");
            if (fileInfoTab)
                fileInfoTab->populate(QFileInfo(filepath));
        }
    }
}
