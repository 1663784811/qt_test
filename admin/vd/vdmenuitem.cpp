#include "vdmenuitem.h"
#include <QLabel>
#include <QSpacerItem>
#include <QHBoxLayout>


VdMenuItem::VdMenuItem(VdMenuData* menuData, QWidget *parent) : QWidget{parent}
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    QWidget* wt = new QWidget(this);
    wt->setObjectName("vdMenuItem");
    vbox->addWidget(wt);
    QHBoxLayout* qh = new QHBoxLayout();
    qh->setContentsMargins(14, 14, 14, 14);
    wt->setLayout(qh);
    // icon
    QLabel* icon = new QLabel();
    icon->setScaledContents(true);
    icon->setMaximumHeight(18);
    icon->setMaximumWidth(18);
    if(!menuData->icon.isEmpty()){
        icon->setPixmap(QPixmap(menuData->icon));
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
        QLabel* status = new QLabel();
        status->setScaledContents(true);
        status->setMaximumHeight(16);
        status->setMaximumWidth(16);
        status->setPixmap(QPixmap(":/vd/vd_status.svg"));
        qh->addWidget(status);
    }else{
        wt->setCursor(Qt::PointingHandCursor);
    }
}

VdMenuItem::~VdMenuItem()
{
}

void VdMenuItem::mousePressEvent(QMouseEvent *event)
{
    // 判断鼠标是否左键点击
    if (event->button() == Qt::LeftButton) {
        emit selectItem("ssss");
    }
    QWidget::mousePressEvent(event);  // 调用基类事件处理
}
