#ifndef MAINFORM_H
#define MAINFORM_H

class QWidget;

#include <QTabWidget>
#include <QDialog>

class MainForm : public QDialog
{
    Q_OBJECT
public:
    explicit MainForm(QWidget* parent = 0);

private:
    QTabWidget *tabWidget;

};

#endif // MAINFORM_H
