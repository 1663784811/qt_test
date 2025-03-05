#include "vdmenu.h"
#include <QVBoxLayout>
#include <QPushButton>


VdMenu::VdMenu(QWidget *parent): QWidget{parent}
{
    // QVBoxLayout* vbox = new QVBoxLayout();
    // for (int var = 0; var < 50; ++var) {
    // }
    // QSpacerItem* v = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    // vbox->addItem(v);
}

void VdMenu::setData(QVector<VdMenuData> *data)
{

    this->updateData(data);
}



void VdMenu::updateData(QVector<VdMenuData> *data)
{
    if(data != nullptr){
        QVBoxLayout* vbox = new QVBoxLayout();
        for(int i = 0; i < data->count(); i++){
            VdMenuData objData = data->at(i);
            qDebug()<<"sssss";
            QPushButton* btn = new QPushButton("ssssssssssss" + i);
            vbox->addWidget(btn);
        }
        setLayout(vbox);
    }
}










