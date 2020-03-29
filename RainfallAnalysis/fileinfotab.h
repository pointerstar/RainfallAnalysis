#ifndef FILEINFOTAB_H
#define FILEINFOTAB_H
#include <QWidget>
#include <QFileInfo>
#include <QLineEdit>
#include <QLabel>
#include "station.h"

class FileInfoTab : public QWidget
{
    Q_OBJECT

public:
    explicit FileInfoTab(Station* stat, QFileInfo finfo, QWidget *parent = 0);

private:
    QLineEdit *fileNameEdit;
    QLabel *fileNameLabel;
    Station* station;
};

#endif // FILEINFOTAB_H
