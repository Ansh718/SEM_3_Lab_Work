#ifndef ANSH_21111_4_H
#define ANSH_21111_4_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Ansh_21111_4; }
QT_END_NAMESPACE

class Ansh_21111_4 : public QMainWindow
{
    Q_OBJECT

public:
    Ansh_21111_4(QWidget *parent = nullptr);
    ~Ansh_21111_4();

private slots:
    void dda(float x1,float y1,float x2,float y2);
    void on_DrawLine_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Ansh_21111_4 *ui;
};
#endif // ANSH_21111_4_H
