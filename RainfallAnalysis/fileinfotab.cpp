#include "fileinfotab.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>


FileInfoTab::FileInfoTab(QString name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);

    fileNameLabel = new QLabel(tr("File Name:"));
    fileNameEdit = new QLineEdit();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(fileNameLabel);
    mainLayout->addWidget(fileNameEdit);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

void FileInfoTab::populate(QFileInfo fileInfo)
{
    fileNameEdit->setText(fileInfo.fileName());
    qDebug() << "we got here: " << fileInfo.fileName();
}
