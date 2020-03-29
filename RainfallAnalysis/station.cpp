#include "station.h"

Station::Station(QObject *parent) : QObject(parent)
{}

void Station::addRecord(DayRainRec r)
{
    dataset << r;
}

void Station::addDay(int month)
{
    monthCount[month]++;
}

void Station::addRain(int month, double rain)
{
    monthRain[month]+=rain;
}

QList<double> Station::getMonthlyAverages() const
{
    QList<double> rain;
    for(int i = 0; i < 12; i++)
        rain[i] = monthRain[i]/monthCount[i];

    return rain;
}
