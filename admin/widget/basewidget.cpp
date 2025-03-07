#include "basewidget.h"
#include <QVBoxLayout>
#include <QSpacerItem>


BaseWidget::BaseWidget(QWidget *parent) : QWidget{parent}
{
    QVBoxLayout* boxLayout = new QVBoxLayout(this);
    mainScroll = new QScrollArea();
    wd = new QWidget();
    mainScroll->setWidget(wd);
    mainScroll->setObjectName("mainscroll");
    mainScroll->setWidgetResizable(true);
    boxLayout->addWidget(mainScroll);
}

void BaseWidget::setLayout(QLayout *layout)
{
    wd->setLayout(layout);
}
