#include "testbtnwidget.h"
#include <QVBoxLayout>
#include <QPushButton>


TestBtnWidget::TestBtnWidget(QWidget *parent) : BaseWidget{parent}
{
    setObjectName("TestBtnWidget");
    QVBoxLayout* boxLayout = new QVBoxLayout();
    for(int i=0;i<100;i++){
        QPushButton* btn = new QPushButton("sss");
        boxLayout->addWidget(btn);
    }
    setLayout(boxLayout);
}
