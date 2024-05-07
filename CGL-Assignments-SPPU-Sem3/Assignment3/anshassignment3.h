#ifndef ANSHASSIGNMENT3_H
#define ANSHASSIGNMENT3_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class anshAssignment3; }
QT_END_NAMESPACE

class anshAssignment3 : public QMainWindow
{
    Q_OBJECT

public:
    anshAssignment3(QWidget *parent = nullptr);
    ~anshAssignment3();

private slots:
    void dda(float x1_,float y1_,float x2_,float y2_);
    void clear();
    int computeCode(double x,double y);
    void cohenSutherland(double x1, double y1, double x2, double y2);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::anshAssignment3 *ui;
};
#endif // ANSHASSIGNMENT3_H
