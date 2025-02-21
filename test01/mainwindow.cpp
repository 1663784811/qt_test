#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsDropShadowEffect>

#define PADDING (10)


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

    ui->widget->setStyleSheet(R"(
        background: #303030
    )");

    // 开户鼠标跟踪
    ui->widget->setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);
    this->centralWidget()->setMouseTracking(true);
    this->setMouseTracking(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *evt)
{

    qDebug() << "mouse down";

    switch (evt->button()) {
    case Qt::RightButton :
        this->close();
        break;
    case Qt::LeftButton :
        isdown = true;
        mOffset = evt->globalPosition().toPoint() - this->pos();
        break;
    default:
        break;
    }


}

void MainWindow::mouseMoveEvent(QMouseEvent *evt)
{
    QRect rect = this->rect();
    QPoint topLeft = mapToGlobal(rect.topLeft());
    QPoint bottomRight = mapToGlobal(rect.bottomRight());
    QPointF globalPos = evt->globalPosition();
    if(isdown){
        QRect rMore(topLeft, bottomRight);
        switch(location)
        {
        case CENTER:
            this->move(evt->globalPosition().toPoint() - mOffset);
            break;
        case TOP:
            rMore.setY(globalPos.y());
            this->setGeometry(rMore);
            break;
        case BOTTOM:
            rMore.setHeight(globalPos.y()-topLeft.y());
            this->setGeometry(rMore);
            break;
        case LEFT:
            rMore.setX(globalPos.x());
            this->setGeometry(rMore);
            break;
        case RIGHT:
            rMore.setWidth(globalPos.x() - topLeft.x());
            this->setGeometry(rMore);
            break;
        case TOP_LEFT:
            rMore.setY(globalPos.y());
            rMore.setX(globalPos.x());
            this->setGeometry(rMore);
            break;
        case TOP_RIGHT:
            rMore.setY(globalPos.y());
            rMore.setWidth(globalPos.x() - topLeft.x());
            this->setGeometry(rMore);
            break;
        case BOTTOM_LEFT:
            rMore.setHeight(globalPos.y()-topLeft.y());
            rMore.setX(globalPos.x());
            this->setGeometry(rMore);
            break;
        case BOTTOM_RIGHT:
            rMore.setHeight(globalPos.y()-topLeft.y());
            rMore.setWidth(globalPos.x() - topLeft.x());
                    this->setGeometry(rMore);
            break;
        default:
            break;
        }

    }else{
        this->setCursorShape(globalPos);
    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *evt)
{
    isdown = false;
    qDebug() << "mouseReleaseEvent";
}

void MainWindow::setCursorShape(QPointF& point)
{
    QRect rect = this->rect();
    QPoint topLeft = mapToGlobal(rect.topLeft());
    QPoint bottomRight = mapToGlobal(rect.bottomRight());
    int x = point.x();
    int y = point.y();

    if(x >= topLeft.x() && x<= topLeft.x() + PADDING && y >= topLeft.y() && y <= topLeft.y() + PADDING){
        // 左上角
        location = TOP_LEFT;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }else if(x <= bottomRight.x() && x >= bottomRight.x() - PADDING && y <= bottomRight.y() && y >= bottomRight.y() - PADDING){
        // 右下角
        location = BOTTOM_RIGHT;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }else if(x >= topLeft.x() && x <= topLeft.x() + PADDING && y <= bottomRight.y() && y >= bottomRight.y() - PADDING){
        // 左下角
        location = BOTTOM_LEFT;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }else if(x <= bottomRight.x() && x>= bottomRight.x() - PADDING && y >= topLeft.y() && y <= topLeft.y() + PADDING){
        // 右上角
        location = TOP_RIGHT;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }else if( x >= topLeft.x() && x<= topLeft.x() + PADDING){
        // 左
        location = LEFT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }else if( x <= bottomRight.x() && x>= bottomRight.x() - PADDING){
        // 右
        location = RIGHT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }else if( y >= topLeft.y() && y <= topLeft.y() + PADDING){
        // 上
        location = TOP;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }else if( y <= bottomRight.y() && y >= bottomRight.y() - PADDING){
        // 下
        location = BOTTOM;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }else{
        // 中间
        location = CENTER;
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}

