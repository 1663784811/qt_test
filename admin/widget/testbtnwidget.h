#ifndef TESTBTNWIDGET_H
#define TESTBTNWIDGET_H

#include <QWidget>
#include "basewidget.h"

class TestBtnWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit TestBtnWidget(QWidget *parent = nullptr);


private:
    QVBoxLayout* boxLayout;
    //


signals:


};

#endif
