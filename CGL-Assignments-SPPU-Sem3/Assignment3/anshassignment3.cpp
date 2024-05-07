#include "anshassignment3.h"
#include "ui_anshassignment3.h"
#include <QImage>
#include <cstdlib>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
QImage img(400,400,QImage::Format_RGB888);
const int ins = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;
int x_max = 300;
int y_max = 300;
int x_min = 10;
int y_min = 10;
anshAssignment3::anshAssignment3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::anshAssignment3)
{
    ui->setupUi(this);
}

anshAssignment3::~anshAssignment3()
{
    delete ui;
}

void anshAssignment3::dda(float x1_, float y1_, float x2_, float y2_)
{
    float dx=x2_-x1_;
    float dy=y2_-y1_;
    float len;
    if (abs(dx)>abs(dy))
    {
        len=abs(dx);
    }
    else
    {
        len=abs(dy);
    }
    float xinc=dx/len;
    float yinc=dy/len;
    int i=0;
    float x=x1_;
    float y=y1_;
    while(i<len)
    {
        img.setPixel(x,y,qRgb(255,255,255));
        x+=xinc;
        y+=yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void anshAssignment3::clear()
{
    for (int i=0;i<400;i++)
    {
        for (int j=0;j<400;j++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
}

int anshAssignment3::computeCode(double x, double y)
{
    int code=ins;
    if(x<x_min)
    {
        code|=LEFT;
    }
    else if(x>x_max)
    {
        code|=RIGHT;
    }
    if(y<y_min)
    {
        code|=BOTTOM;
    }
    else if(y>y_max)
    {
        code|=TOP;
    }
    return code;
}

void anshAssignment3::cohenSutherland(double x1, double y1, double x2, double y2)
{
    int code1=computeCode(x1,y1);
    int code2=computeCode(x2,y2);
    bool accept=false;
    while(true)
    {
        if(code1==0 && code2==0)
        {
            accept=true;
            break;
        }
        else if(code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;
            if (code1 != 0)
            {
                code_out = code1;
            }
            else
            {
                code_out = code2;
            }
            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout << x1 << ", "<< y1 << " to " << x2 << ", " << y2 << endl;
        dda(float (x1),float (y1),float (x2),float (y2));
    }
    else
    {
        cout << "Line not in bounds" << endl;
    }

}


void anshAssignment3::on_pushButton_clicked()
{
    clear();
    float x1,y1,x2,y2;
    x1=ui->plainTextEdit->toPlainText().toFloat();
    y1=ui->plainTextEdit_2->toPlainText().toFloat();
    x2=ui->plainTextEdit_3->toPlainText().toFloat();
    y2=ui->plainTextEdit_4->toPlainText().toFloat();
    dda(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void anshAssignment3::on_pushButton_2_clicked()
{
    clear();
    float x1,y1,x2,y2,bx1,by1,l,b;
    x1=ui->plainTextEdit->toPlainText().toFloat();
    y1=ui->plainTextEdit_2->toPlainText().toFloat();
    x2=ui->plainTextEdit_3->toPlainText().toFloat();
    y2=ui->plainTextEdit_4->toPlainText().toFloat();
    bx1=ui->plainTextEdit_5->toPlainText().toFloat();
    by1=ui->plainTextEdit_6->toPlainText().toFloat();
    l=ui->plainTextEdit_7->toPlainText().toFloat();
    b=ui->plainTextEdit_8->toPlainText().toFloat();
    dda(bx1,by1,bx1+b,by1);
    dda(bx1+b,by1,bx1+b,by1+l);
    dda(bx1+b,by1+l,bx1,by1+l);
    dda(bx1,by1+l,bx1,by1);
    x_min = bx1;
    x_max = bx1 + b;
    y_min = by1;
    y_max = by1+l;
    cohenSutherland(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


//void anshAssignment3::on_pushButton_3_clicked()
//{
//    float bx1,by1,l,b;
//    bx1=ui->plainTextEdit_5->toPlainText().toFloat();
//    by1=ui->plainTextEdit_6->toPlainText().toFloat();
//    l=ui->plainTextEdit_7->toPlainText().toFloat();
//    b=ui->plainTextEdit_8->toPlainText().toFloat();
//    dda(bx1,by1,bx1+b,by1);
//    dda(bx1+b,by1,bx1+b,by1+l);
//    dda(bx1+b,by1+l,bx1,by1+l);
//    dda(bx1,by1+l,bx1,by1);
//    ui->label->setPixmap(QPixmap::fromImage(img));
//}

