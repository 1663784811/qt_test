#include "testbtnwidget.h"
#include <QVBoxLayout>
#include <QPushButton>


TestBtnWidget::TestBtnWidget(QWidget *parent) : QWidget{parent}
{
    setObjectName("TestBtnWidget");

    QVBoxLayout* boxLayout = new QVBoxLayout(this);
    for(int i=0;i<100;i++){
        QPushButton* btn = new QPushButton("sss");
        boxLayout->addWidget(btn);


    }



    // boxLayout->addItem();

}
