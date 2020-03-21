#include "mainform.h"
#include "fileinfotab.h"
#include <QVBoxLayout>

MainForm::MainForm(QWidget *parent): QDialog(parent)
{
    tabWidget = new QTabWidget();
    tabWidget->addTab(new FileInfoTab, tr("File Info"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);//this sorts out parentage as I recall.

}
