#ifndef HISTORYR_H
#define HISTORYR_H

#include <QDialog>

namespace Ui {
class historyr;
}

class historyr : public QDialog
{
    Q_OBJECT

public:
    explicit historyr(QWidget *parent = 0);
    ~historyr();
public slots:
    void fun_close();
    void updaterList(const QList<int> &resistorList);

private:
    Ui::historyr *ui;
    QList<int> list;
};

#endif // HISTORYR_H
