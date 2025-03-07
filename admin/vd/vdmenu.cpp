#include "vdmenu.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include "vdmenuitem.h"


VdMenu::VdMenu(QWidget *parent): QWidget{parent}
{
    vbMenuLayout = new QVBoxLayout(this);
    vbMenuLayout->setContentsMargins(0, 0, 0, 0);
    vbMenuLayout->setSpacing(0);
    vbLastItem = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
}

void VdMenu::setData(QVector<VdMenuData> *data)
{
    this->updateData(data,vbMenuLayout);
    vbMenuLayout->removeItem(vbLastItem);
    vbMenuLayout->addItem(vbLastItem);
}



void VdMenu::updateData(QVector<VdMenuData> *data, QVBoxLayout* loayout)
{
    if(data != nullptr){
        for(int i = 0; i < data->count(); i++){
            VdMenuData objData = data->at(i);
            VdMenuItem* item = new VdMenuItem(&objData);
            loayout->addWidget(item);
            connect(item, &VdMenuItem::selectItem, this , [=](QString id){
                qDebug() << " id= " << id;
            });
            if(objData.childs.count() > 0){
                QVBoxLayout* vbox = new QVBoxLayout();
                vbox->setContentsMargins(0, 0, 0, 0);
                vbox->setSpacing(0);
                QWidget* wg = new QWidget(this);
                this->updateData(&objData.childs,vbox);
                wg->setLayout(vbox);
                loayout->addWidget(wg);
            }
        }
    }
}










