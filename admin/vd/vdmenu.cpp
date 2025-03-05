#include "vdmenu.h"
#include <QVBoxLayout>
#include <QPushButton>


VdMenu::VdMenu(QWidget *parent): QWidget{parent}
{
}

void VdMenu::setData(QVector<VdMenuData> *data)
{
    QVBoxLayout* vbox = new QVBoxLayout();
    this->updateData(data);
    setLayout(vbox);
}



void VdMenu::updateData(QVector<VdMenuData> *data)
{
    if(data != nullptr){
        QVBoxLayout* vbox = new QVBoxLayout();
        for(int i = 0; i < data->count(); i++){
            VdMenuData objData = data->at(i);
            qDebug()<<"s::" << objData.name;
            QPushButton* btn = new QPushButton("sss");
            vbox->addWidget(btn);
        }
        setLayout(vbox);
    }
}










