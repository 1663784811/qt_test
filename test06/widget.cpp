#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    this->setMinimumWidth(600);
    this->setMinimumHeight(400);
    QHBoxLayout* mainlayout = new QHBoxLayout(this);
    //
    QWidget* navWidget = new QWidget(this);
    QWidget* mainWidget = new QWidget(this);
    mainlayout->addWidget(navWidget);
    mainlayout->addWidget(mainWidget);
    QVBoxLayout* navLayout = new QVBoxLayout(this);
    navWidget->setLayout(navLayout);
    this->setLayout(mainlayout);


    QPushButton* btn = new QPushButton(this);
    btn->setText("sssssss");


}

Widget::~Widget() {

}

void Widget::initNav()
{

    // navLayout->addWidget(btn);
    // QStringList s;
    // for(int i=0; i< ; i++){

    // }

}
