#ifndef HISTORYR_H
#define HISTORYR_H

#include <QDialog>
#include <QTimer>
#include <QPainter>;

namespace Ui {
class historyr;
}

class historyr : public QDialog
{
    Q_OBJECT

public:
    QList<int> List;
    explicit historyr(QWidget *parent = 0);
    ~historyr();
signals:
  
public slots:
    void fun_close();
    void fun_draw();

private:
    Ui::historyr *ui;
    QTimer t1;

    
};

#endif // HISTORYR_H
