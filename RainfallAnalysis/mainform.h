#ifndef MAINFORM_H
#define MAINFORM_H

class QWidget;

#include <QPushButton>
#include <QTabWidget>
#include <QDialog>
#include <QFileInfo>

class MainForm : public QDialog
{
    Q_OBJECT
public:
    explicit MainForm(QWidget* parent = 0);

public slots:
    void navigateToFile();

private:
    QTabWidget *tabWidget;
    QPushButton *selectFile;

    void populate(QFileInfo fileinfo);

};

#endif // MAINFORM_H
