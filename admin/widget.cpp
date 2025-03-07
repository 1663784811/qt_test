#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <vd/vdmenu.h>
#include "widget/testbtnwidget.h"


Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::mainWin)
{
    ui->setupUi(this);

    VdMenu *menu = new VdMenu();
    QVector<VdMenuData> *data = new QVector<VdMenuData>();
    for (int i = 0; i < 5; ++i) {
        VdMenuData v;
        v.id = "ssss";
        v.name = "name";
        v.icon = ":/vd/vd_component.svg";
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
    menu->setData(data);
    ui->leftscroll->setWidget(menu);
    // 接收信号
    connect(menu, &VdMenu::selectItem, this, &Widget::selectMenu);


    TestBtnWidget* btnWidget = new TestBtnWidget();

    ui->stackedWidget->addWidget(btnWidget);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectMenu()
{
    qDebug()<< "selectMenu";
}
