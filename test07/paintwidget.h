#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>


enum Shape{
    _Point,
    _Line,

    _Rect,
    _RoundedRect,
    _Ellipse,

    _Polyline,
    _Polygon,

    _Arc,
    _Pie,
    _Chord,

    _Path,

    _Text,
    _Pixmap
};


class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);

signals:
};

#endif // PAINTWIDGET_H
