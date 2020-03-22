#include "mainform.h"
#include "fileinfotab.h"
#include <QVBoxLayout>
#include <QFileDialog>

MainForm::MainForm(QWidget *parent): QDialog(parent)
{
    tabWidget = new QTabWidget();
    tabWidget->addTab(new FileInfoTab("fileinfo"), tr("File Info"));
    selectFile = new QPushButton(tr("Select file"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(selectFile);
    setLayout(mainLayout);//this sorts out parentage

    connect(selectFile, SIGNAL (released()), this, SLOT (navigateToFile()));

}

void MainForm::navigateToFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Get Any File");
    if (!filePath.isEmpty())
        populate(QFileInfo(filePath));

}

void MainForm::populate(QFileInfo fileinfo)
{
    QString childName = "fileInfo";
    FileInfoTab* fileInfoTab = findChild<FileInfoTab*>("fileInfo");
    if (fileInfoTab)
        fileInfoTab->populate(fileinfo);

}
