#include "anshassignment2.h"
#include "ui_anshassignment2.h"
#include "QMouseEvent"
#include <iostream>
#include <algorithm>
#include <QColorDialog>
using namespace std;
QColor c;
QImage img(500,500,QImage::Format_RGB888);
anshAssignment2::anshAssignment2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::anshAssignment2)
{
    ui->setupUi(this);
    start=true;
    ver=0;
}
anshAssignment2::~anshAssignment2()
{
    delete ui;
}
void anshAssignment2::dda(float x1, float y1, float x2, float y2)
{
    float dx=x2-x1;
    float dy=y2-y1;
    float len;
    if (abs(dx)>=abs(dy))
    {
            len=abs(dx);
    }
    else
    {
            len=abs(dy);
    }
    float xinc=dx/len;
    float yinc=dy/len;
    float x=x1;
    float y=y1;
    int i=0;
    while(i<len)
    {
        x+=xinc;
        y+=yinc;
        img.setPixel(x,y,c.rgb());
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void anshAssignment2::mousePressEvent(QMouseEvent *event)
{
    if(start)
    {
        int p= event->pos().x();
        int q= event->pos().y();
        a[ver]=p;
        b[ver]=q;

        if(event->button()==Qt::RightButton)
        {
            dda(a[ver-1],b[ver-1],a[0],b[0]);
            start=false;
        }
        else
        {
            if(ver>0)
            {
                dda(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
}
void anshAssignment2::on_pushButton_clicked()
{
    int i;
    float dx,dy;
    a[ver]=a[0];
    b[ver]=b[0];
    for (i=0;i<ver;i++)
    {
        dx=a[i+1]-a[i];
        dy=b[i+1]-b[i];
        if(dy==0.0f)
        {
            slope[i]=1.0;
        }
        if(dx==0.0f)
        {
            slope[i]=0.0;
        }
        if((dy!=0.0f)&&(dx!=0.0f))
        {
            slope[i]=dx/dy;
        }
    }
    for (int y=0;y<500;y++)
    {
        k=0;
        for (i=0;i<ver;i++)
        {
            if((b[i]<=y&&b[i+1]>y)||(b[i]>y&&b[i+1]<=y))
            {
                xi[k]=int(a[i]+slope[i]*(y-b[i]));
                k++;
            }
        }
        sort(xi,xi+k);
        for(i=0;i<k;i+=2)
        {
            dda(xi[i],y,xi[i+1]+1,y);
        }
    }
}
void anshAssignment2::on_pushButton_2_clicked()
{
    c= QColorDialog::getColor();
}

