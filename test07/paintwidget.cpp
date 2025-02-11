#include "paintwidget.h"
#include <QPainter>

PaintWidget::PaintWidget(QWidget *parent): QWidget{parent}
{
    this->setAttribute(Qt::WA_StyledBackground, true);

}


void PaintWidget::setShape(Shape shape)
{
    this->mShape = shape;
    update();
}


void PaintWidget::paintEvent(QPaintEvent *event)
{
    static const QPoint points[4] = {
        QPoint(10,80),
        QPoint(20,10),
        QPoint(80,30),
        QPoint(90,70),
    };
    QPainter painter(this);

    for(int x=0; x < width(); x+= 100){
        for(int y=0; y < height(); y+= 100){
            painter.save();
            painter.translate(x, y);

            switch(mShape){
            case _Point:
                painter.drawPoints(points,4);
                break;
            case _Line:
                painter.drawLine(points[0], points[2]);
                break;
            }
            painter.restore();
        }
    }



}


