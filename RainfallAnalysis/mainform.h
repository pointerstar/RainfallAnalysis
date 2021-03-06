#ifndef MAINFORM_H
#define MAINFORM_H

class QWidget;

#include <QPushButton>
#include <QTabWidget>
#include <QDialog>
#include <QFileInfo>
#include "station.h"

class MainForm : public QDialog
{
    Q_OBJECT
public:
    explicit MainForm(QWidget* parent = 0);

public slots:
    void attemptStationLoad();

private:
    QTabWidget *tabWidget;
    QPushButton *selectFile;
    bool fileSuccess(QString &filePath);
    bool readStationData(QString filePath, Station* stat);
};

#endif // MAINFORM_H
