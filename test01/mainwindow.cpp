#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //在相应Widget的构造函数里
    //设置无边框窗口
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    //设置主窗口透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(10);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);
    ui->widget->setGraphicsEffect(shadow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *evt)
{
    isdown = true;
    mOffset = evt->globalPosition().toPoint() - this->pos();
    qDebug() << "mouse down";
}

void MainWindow::mouseMoveEvent(QMouseEvent *evt)
{
    if(isdown){
        this->move(evt->globalPosition().toPoint()-mOffset);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *evt)
{
    isdown = false;
}

