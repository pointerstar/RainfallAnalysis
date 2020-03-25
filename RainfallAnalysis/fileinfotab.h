#ifndef FILEINFOTAB_H
#define FILEINFOTAB_H
#include <QWidget>
#include <QFileInfo>
#include <QLineEdit>
#include <QLabel>

class FileInfoTab : public QWidget
{
    Q_OBJECT

public:
    explicit FileInfoTab(QString name, QWidget *parent = 0);
    void populate(QFileInfo fileinfo);

private:
    QLineEdit *fileNameEdit;
    QLabel *fileNameLabel;
};

#endif // FILEINFOTAB_H
