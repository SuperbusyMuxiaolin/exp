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

private:
    Ui::historyr *ui;
};

#endif // HISTORYR_H
