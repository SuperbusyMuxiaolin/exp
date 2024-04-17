#ifndef HISTORYR_H
#define HISTORYR_H

#include <QDialog>
#include <QTimer>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QtGui>

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
protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

private:
    Ui::historyr *ui;
    QTimer t1;
    QImage image;

    
};

#endif // HISTORYR_H
