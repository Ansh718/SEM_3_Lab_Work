#include "anshassignment5.h"
#include "ui_anshassignment5.h"
#include"QImage"
QImage img(700,700,QImage::Format_RGB888);
anshAssignment5::anshAssignment5(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::anshAssignment5)
{
    ui->setupUi(this);
    int x=20;
    int y=500;
    HilbertCurve(1,2,3,4,5,6,x,y);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
anshAssignment5::~anshAssignment5()
{
    delete ui;
}

void anshAssignment5::DDA(float x1, float y1, float x2, float y2)
{
    float dx=x2-x1;
    float dy=y2-y1;
    float len;
    if (abs(dx)>abs(dy))
    {
        len=abs(dx);
    }
    else
    {
        len=abs(dy);
    }
    int i=0;
    float x=x1;
    float y=y1;
    float xinc=dx/len;
    float yinc=dy/len;
    while(i<len)
    {
        img.setPixel(x,y,qRgb(255,255,255));
        x+=xinc;
        y+=yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void anshAssignment5::HilbertCurve(int u, int r, int d, int l, int h, int i, int &x, int &y)
{
    if(i<=0)
    {
        return;
    }
    i--;
    HilbertCurve(r,u,l,d,h,i,x,y);
    Iterate(u,h,x,y);
    HilbertCurve(u,r,d,l,h,i,x,y);
    Iterate(r,h,x,y);
    HilbertCurve(u,r,d,l,h,i,x,y);
    Iterate(d,h,x,y);
    HilbertCurve(l,d,r,u,h,i,x,y);
}

void anshAssignment5::Iterate(int j, int h, int &x, int &y)
{
    int x1=x,y1=y;
    switch(j)
    {

    case 1:
        y-=h;
        break;
    case 2:
        x+=h;
        break;
    case 4:
        x-=h;

        break;
    case 3 :
        y+=h;
        break;

    }
    DDA(x1,y1,x,y);
}

int anshAssignment5::Sign(int x)
{
    if(x==0)
    {
        return 0;
    }
    if(x>0)
    {
        return 1;
    }
    return -1;
}


