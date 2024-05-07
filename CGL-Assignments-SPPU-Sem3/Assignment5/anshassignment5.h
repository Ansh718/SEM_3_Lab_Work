#ifndef ANSHASSIGNMENT5_H
#define ANSHASSIGNMENT5_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class anshAssignment5; }
QT_END_NAMESPACE

class anshAssignment5 : public QMainWindow
{
    Q_OBJECT

public:
    anshAssignment5(QWidget *parent = nullptr);
    ~anshAssignment5();
private slots:
    void DDA(float x1, float y1, float x2, float y2);
    void HilbertCurve(int u, int r, int d, int l, int h, int i, int &x, int &y);
    void Iterate(int j, int h, int &x, int &y);
    int Sign(int x);

private:
    Ui::anshAssignment5 *ui;
};
#endif // ANSHASSIGNMENT5_H
