#ifndef ANSHASSIGNMENT2_H
#define ANSHASSIGNMENT2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class anshAssignment2; }
QT_END_NAMESPACE

class anshAssignment2 : public QMainWindow
{
    Q_OBJECT

public:
    anshAssignment2(QWidget *parent = nullptr);
    ~anshAssignment2();
    void dda(float x1,float y1,float x2,float y2);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::anshAssignment2 *ui;
    int a[20],b[20],ver,j,temp,k,i,xi[20];
    float slope[20],dx,dy;
    bool start;
};
#endif // ANSHASSIGNMENT2_H
