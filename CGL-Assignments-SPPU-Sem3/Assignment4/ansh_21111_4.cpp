#include "ansh_21111_4.h"
#include "ui_ansh_21111_4.h"
#include "math.h"
#include "QImage"
#include <iostream>
#include <cmath>
using namespace std;

QImage img(500,500,QImage::Format_RGB888);
Ansh_21111_4::Ansh_21111_4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ansh_21111_4)
{
    ui->setupUi(this);
}

Ansh_21111_4::~Ansh_21111_4()
{
    delete ui;
}

void Ansh_21111_4::dda(float x1, float y1, float x2, float y2)
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
        img.setPixel(x,y,qRgb(255,255,255));
        x+=xinc;
        y+=yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void Ansh_21111_4::on_DrawLine_clicked()
{
    dda(0,250,500,250);
    dda(250,0,250,500);
    float x1,y1,x2,y2,x3,y3;
    x1=ui->plainTextEdit->toPlainText().toFloat();
    y1=ui->plainTextEdit_2->toPlainText().toFloat();
    x2=ui->plainTextEdit_3->toPlainText().toFloat();
    y2=ui->plainTextEdit_4->toPlainText().toFloat();
    x3=ui->plainTextEdit_5->toPlainText().toFloat();
    y3=ui->plainTextEdit_6->toPlainText().toFloat();
    dda(x1+250,y1+250,x2+250,y2+250);
    dda(x2+250,y2+250,x3+250,y3+250);
    dda(x3+250,y3+250,x1+250,y1+250);
}

void Ansh_21111_4::on_pushButton_2_clicked()
{
    float x1,y1,x2,y2,x3,y3,tx,ty;
    x1=ui->plainTextEdit->toPlainText().toFloat();
    y1=ui->plainTextEdit_2->toPlainText().toFloat();
    x2=ui->plainTextEdit_3->toPlainText().toFloat();
    y2=ui->plainTextEdit_4->toPlainText().toFloat();
    x3=ui->plainTextEdit_5->toPlainText().toFloat();
    y3=ui->plainTextEdit_6->toPlainText().toFloat();
    tx=ui->plainTextEdit_7->toPlainText().toFloat();
    ty=ui->plainTextEdit_8->toPlainText().toFloat();
    dda(x1+250+tx,y1+250+ty,x2+250+tx,y2+250+ty);
    dda(x2+250+tx,y2+250+ty,x3+250+tx,y3+250+ty);
    dda(x3+250+tx,y3+250+ty,x1+250+tx,y1+250+ty);
}

void Ansh_21111_4::on_pushButton_3_clicked()
{
    float x1,y1,x2,y2,x3,y3,sx,sy;
    x1=ui->plainTextEdit->toPlainText().toFloat();
    y1=ui->plainTextEdit_2->toPlainText().toFloat();
    x2=ui->plainTextEdit_3->toPlainText().toFloat();
    y2=ui->plainTextEdit_4->toPlainText().toFloat();
    x3=ui->plainTextEdit_5->toPlainText().toFloat();
    y3=ui->plainTextEdit_6->toPlainText().toFloat();
    sx=ui->plainTextEdit_9->toPlainText().toFloat();
    sy=ui->plainTextEdit_10->toPlainText().toFloat();
    dda((x1*sx)+250,(y1*sy)+250,(x2*sx)+250,(y2*sy)+250);
    dda((x2*sx)+250,(y2*sy)+250,(x3*sx)+250,(y3*sy)+250);
    dda((x3*sx)+250,(y3*sy)+250,(x1*sx)+250,(y1*sy)+250);
}

void Ansh_21111_4::on_pushButton_4_clicked()
{
    float x1,y1,x2,y2,x3,y3,theta;
    x1=ui->plainTextEdit->toPlainText().toFloat();
    y1=ui->plainTextEdit_2->toPlainText().toFloat();
    x2=ui->plainTextEdit_3->toPlainText().toFloat();
    y2=ui->plainTextEdit_4->toPlainText().toFloat();
    x3=ui->plainTextEdit_5->toPlainText().toFloat();
    y3=ui->plainTextEdit_6->toPlainText().toFloat();
    theta=ui->plainTextEdit_11->toPlainText().toFloat();
    float RA=((theta)*(0.01745));
    float X1,Y1,X2,Y2,X3,Y3;
        X1=x1*cos(RA)-y1*sin(RA);
        Y1=x1*sin(RA)+y1*cos(RA);
        X2=x2*cos(RA)-y2*sin(RA);
        Y2=x2*sin(RA)+y2*cos(RA);
        X3=x3*cos(RA)-y3*sin(RA);
        Y3=x3*sin(RA)+y3*cos(RA);
    dda(X1+250,Y1+250,X2+250,Y2+250);
    dda(X2+250,Y2+250,X3+250,Y3+250);
    dda(X3+250,Y3+250,X1+250,Y1+250);
}
