#include "anshassignment1.h"
#include "ui_anshassignment1.h"
#include "math.h"

QImage img(500,500,QImage::Format_RGB888);
anshAssignment1::anshAssignment1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::anshAssignment1)
{
    ui->setupUi(this);
}

anshAssignment1::~anshAssignment1()
{
    delete ui;
}

void anshAssignment1::DDA(float x1, float y1, float x2, float y2)
{
    float dx=x2-x1,dy=y2-y1,len;
    if(abs(dx)>abs(dy))
    {
        len=abs(dx);
    }
    else
    {
        len=abs(dy);
    }
    float xinc=dx/len,yinc=dy/len,x=x1,y=y1;
    int i=0;
    while(i<len)
    {
        img.setPixel(x,y,qRgb(255,0,255));
        x+=xinc;
        y+=yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void anshAssignment1::Circle(float Xc, float Yc, float r)
{
    float x=0,y=r,d=3-2*r;
    while(y>=x)
    {
        img.setPixel(Xc+x,Yc+y,qRgb(255,255,0));
        img.setPixel(Xc-x,Yc+y,qRgb(255,255,0));
        img.setPixel(Xc+x,Yc-y,qRgb(255,255,0));
        img.setPixel(Xc-x,Yc-y,qRgb(255,255,0));
        img.setPixel(Xc+y,Yc+x,qRgb(255,255,0));
        img.setPixel(Xc-y,Yc+x,qRgb(255,255,0));
        img.setPixel(Xc+y,Yc-x,qRgb(255,255,0));
        img.setPixel(Xc+-y,Yc-x,qRgb(255,255,0));
        x+=1;
        if(d>0)
        {
            y-=1;
            d+=4*(x-y)+10;
        }
        else
        {
            d+=4*x+6;
        }
    }
}


void anshAssignment1::on_pushButton_clicked()
{
    float X1,Y1,Length,Breadth;
    X1=ui->plainTextEdit->toPlainText().toFloat();
    Y1=ui->plainTextEdit_2->toPlainText().toFloat();
    Length=ui->plainTextEdit_3->toPlainText().toFloat();
    Breadth=ui->plainTextEdit_4->toPlainText().toFloat();
    DDA(X1,Y1,X1+Length,Y1);
    DDA(X1+Length,Y1,X1+Length,Y1+Breadth);
    DDA(X1+Length,Y1+Breadth,X1,Y1+Breadth);
    DDA(X1,Y1+Breadth,X1,Y1);
    DDA(X1+(Length/2),Y1,X1+Length,Y1+(Breadth)/2);
    DDA(X1+Length,Y1+(Breadth)/2,X1+(Length/2),Y1+Breadth);
    DDA(X1+(Length/2),Y1+Breadth,X1,Y1+(Breadth)/2);
    DDA(X1,Y1+(Breadth)/2,X1+(Length/2),Y1);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void anshAssignment1::on_pushButton_2_clicked()
{
    float X1,Y1,Length,Breadth;
    X1=ui->plainTextEdit->toPlainText().toFloat();
    Y1=ui->plainTextEdit_2->toPlainText().toFloat();
    Length=ui->plainTextEdit_3->toPlainText().toFloat();
    Breadth=ui->plainTextEdit_4->toPlainText().toFloat();
    float Xc_,Yc_,r_;
    Xc_=X1+(Length/2);
    Yc_=Y1+(Breadth)/2;
    r_=sqrt((Length*Length+Breadth*Breadth)/16);
    Circle(Xc_,Yc_,r_);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

