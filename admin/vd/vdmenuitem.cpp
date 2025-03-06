#include "vdmenuitem.h"
#include <QLabel>
#include <QSpacerItem>
#include <QHBoxLayout>


VdMenuItem::VdMenuItem(VdMenuData* menuData, QWidget *parent) : QWidget{parent}
{
    qh = new QHBoxLayout(this);
    // icon
    QPixmap pixmap(":/vd/vd_component.svg");
    QLabel* icon = new QLabel();
    icon->setScaledContents(true);
    icon->setMaximumHeight(16);
    icon->setMaximumWidth(16);
    icon->setPixmap(pixmap);
    qh->addWidget(icon);
    // name
    QLabel* name = new QLabel(menuData->name);
    qh->addWidget(name);
    // ====
    QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    qh->addItem(horizontalSpacer);
    if(menuData->childs.count() > 0){
        // open status
        QPixmap st(":/vd/vd_status.svg");
        QLabel* status = new QLabel();
        status->setScaledContents(true);
        status->setMaximumHeight(16);
        status->setMaximumWidth(16);
        status->setPixmap(st);
        qh->addWidget(status);
    }
}

void VdMenuItem::mousePressEvent(QMouseEvent *event)
{
    // 判断鼠标是否左键点击
    if (event->button() == Qt::LeftButton) {
        emit selectItem("ssss");
    }
    QWidget::mousePressEvent(event);  // 调用基类事件处理
}
