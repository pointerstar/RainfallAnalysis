#ifndef FILEINFOTAB_H
#define FILEINFOTAB_H
#include <QWidget>
#include <QFileInfo>

class FileInfoTab : public QWidget
{
    Q_OBJECT

public:
    explicit FileInfoTab(QString name, QWidget *parent = 0);
    void populate(QFileInfo fileinfo);
};

#endif // FILEINFOTAB_H
