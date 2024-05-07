#ifndef ANSHASSIGNMENT1_H
#define ANSHASSIGNMENT1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class anshAssignment1; }
QT_END_NAMESPACE

class anshAssignment1 : public QMainWindow
{
    Q_OBJECT

public:
    anshAssignment1(QWidget *parent = nullptr);
    ~anshAssignment1();

private slots:
    void DDA (float,float,float,float);
    void Circle(float,float,float);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::anshAssignment1 *ui;
};
#endif // ANSHASSIGNMENT1_H
