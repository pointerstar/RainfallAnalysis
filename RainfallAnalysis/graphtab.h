#ifndef GRAPHTAB_H
#define GRAPHTAB_H

#include <QWidget>
#include "station.h"

class graphTab : public QWidget
{
    Q_OBJECT
public:
    explicit graphTab(Station* stat, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // GRAPHTAB_H
