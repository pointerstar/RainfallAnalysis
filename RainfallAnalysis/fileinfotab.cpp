#include "fileinfotab.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>


FileInfoTab::FileInfoTab(QString name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);

    QLabel *fileNameLabel = new QLabel(tr("File Name:"));
    QLineEdit *fileNameEdit = new QLineEdit();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(fileNameLabel);
    mainLayout->addWidget(fileNameEdit);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

void FileInfoTab::populate(QFileInfo fileInfo)
{

}
