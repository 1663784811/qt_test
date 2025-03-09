#include "widget.h"



Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::mainWin)
{
    ui->setupUi(this);

    VdMenu *menu = new VdMenu();
    menuData = new QVector<VdMenuData>();
    VdMenuData component;
    component.id = "component";
    component.icon = ":/vd/vd_component.svg";
    component.name = "组件";
    QVector<VdMenuData> chd;

    VdMenuData text;
    text.id = "text";
    text.icon = ":/vd/vd_component.svg";
    text.name = "文本";
    chd.append(text);

    VdMenuData btnComponent;
    btnComponent.id = "btn";
    btnComponent.icon = ":/vd/vd_component.svg";
    btnComponent.name = "按钮";
    chd.append(btnComponent);

    VdMenuData switchBtn;
    switchBtn.id = "switchBtn";
    switchBtn.icon = ":/vd/vd_component.svg";
    switchBtn.name = "开关";
    chd.append(switchBtn);

    component.childs = chd;
    menuData->append(component);

    for (int i = 0; i < 5; ++i) {
        VdMenuData v;
        v.id = "ssss";
        v.name = "组件";
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
        menuData->append(v);
    }
    menu->setData(menuData);
    ui->leftscroll->setWidget(menu);

    // 接收信号
    connect(menu, &VdMenu::selectItem, this, &Widget::selectMenu);






    widgetList.insert("btnWidget", new TestBtnWidget());

    int i = 0;
    foreach (QString key, widgetList.keys()) {
        ui->stackedWidget->addWidget(widgetList.value(key));
        widgetIndex.insert(key, i);
        i++;
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectMenu()
{
    qDebug()<< "selectMenu";


}
