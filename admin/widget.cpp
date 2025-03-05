#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <vd/vdmenu.h>


Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget)
{
    ui->setupUi(this);

    VdMenu *menu = new VdMenu();
    QVector<VdMenuData> *data = new QVector<VdMenuData>();

    for (int i = 0; i < 60; ++i) {
        VdMenuData v;
        v.setId("sss");
        v.setName("name");
        data->append(v);
    }
    menu->setData(data);
    ui->leftscroll->setWidget(menu);
}

Widget::~Widget()
{
    delete ui;
}
