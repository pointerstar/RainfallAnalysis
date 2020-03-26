#include "station.h"

Station::Station(QObject *parent) : QObject(parent)
{}

void Station::addRecord(DayRainRec r)
{
    dataset << r;
}
