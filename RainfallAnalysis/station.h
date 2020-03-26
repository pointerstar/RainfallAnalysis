#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QDate>

struct DayRainRec
{
    DayRainRec() {}
    QDate day;
    double rain;
    int qualCode;
};

class Station : public QObject
{
    Q_OBJECT
public:
    explicit Station(QObject *parent = nullptr);
    void addRecord(DayRainRec r);

private:
    QString stationName;
    QList<DayRainRec> dataset;

};

#endif // STATION_H
