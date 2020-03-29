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
    void addDay(int month);
    void addRain(int month, double rain);
    QList<double> getMonthlyAverages() const;

private:
    QString stationName;
    QList<DayRainRec> dataset;
    int monthCount[12];
    double monthRain[12];

};

#endif // STATION_H
