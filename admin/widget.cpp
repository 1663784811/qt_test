#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <vd/vdmenu.h>


Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::mainWin)
{
    ui->setupUi(this);

    VdMenu *menu = new VdMenu();
    QVector<VdMenuData> *data = new QVector<VdMenuData>();

    for (int i = 0; i < 60; ++i) {
        VdMenuData v;
        v.id = "ssss";
        v.name = "name";
        if(i%5 == 0){
            QVector<VdMenuData> childs;
            for(int j=0;j<4;j++){
                VdMenuData x;
                x.id = "fff";
                x.name = "sss";
                childs.append(x);
            }
            v.childs = childs;
        }
        data->append(v);
    }
    menu->setData(data);
    ui->leftscroll->setWidget(menu);
}

Widget::~Widget()
{
    delete ui;
}
