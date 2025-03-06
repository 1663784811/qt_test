#include "vdmenuitem.h"
#include <QLabel>
#include <QSpacerItem>
#include <QHBoxLayout>


VdMenuItem::VdMenuItem(VdMenuData* menuData, QWidget *parent) : QWidget{parent}
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    QWidget* wt = new QWidget();
    wt->setObjectName("vdMenuItem");
    vbox->addWidget(wt);
    QHBoxLayout* qh = new QHBoxLayout();
    wt->setLayout(qh);
    // icon
    QLabel* icon = new QLabel();
    icon->setScaledContents(true);
    icon->setMaximumHeight(16);
    icon->setMaximumWidth(16);
    if(!menuData->icon.isEmpty()){
        QPixmap pixmap(menuData->icon);
        icon->setPixmap(pixmap);
    }
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
