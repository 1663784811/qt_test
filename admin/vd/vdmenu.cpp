#include "vdmenu.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>


VdMenu::VdMenu(QWidget *parent): QWidget{parent}
{
    setStyleSheet(QString::fromUtf8(".{background-color: #cccccc;}"));
}

void VdMenu::setData(QVector<VdMenuData> *data)
{
    QVBoxLayout* vbox = new QVBoxLayout();
    this->updateData(data,vbox);
    QSpacerItem* v = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    vbox->addItem(v);
    setLayout(vbox);
}



void VdMenu::updateData(QVector<VdMenuData> *data, QVBoxLayout* loayout)
{
    if(data != nullptr){

        for(int i = 0; i < data->count(); i++){
            VdMenuData objData = data->at(i);
            // ===
            QWidget* item = new QWidget(this);
            QHBoxLayout* qh = new QHBoxLayout(this);
            // icon
            QPixmap pixmap(":/vd/vd_component.svg");
            QLabel* icon = new QLabel(this);
            icon->setScaledContents(true);
            icon->setMaximumHeight(16);
            icon->setMaximumWidth(16);
            icon->setPixmap(pixmap);
            //icon->setScaledContents(true);
            qh->addWidget(icon);
            // name
            QLabel* name = new QLabel(objData.name) ;
            qh->addWidget(name);
            // ====
            QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
            qh->addItem(horizontalSpacer);
            if(objData.childs.count() > 0){
                // open status
                QPixmap st(":/vd/vd_status.svg");
                QLabel* status = new QLabel(this);
                status->setScaledContents(true);
                status->setMaximumHeight(16);
                status->setMaximumWidth(16);
                status->setPixmap(st);
                qh->addWidget(status);
            }
            item->setLayout(qh);
            loayout->addWidget(item);
            // ===
            item->setStyleSheet(QString::fromUtf8(".QWidget{background-color: #ffffff;} .QWidget:hover { background-color: yellow; }"));
            loayout->setContentsMargins(0, 0, 0, 0);
            loayout->setSpacing(0);

            if(objData.childs.count() > 0){
                QVBoxLayout* vbox = new QVBoxLayout();
                QWidget* wg = new QWidget(this);
                this->updateData(&objData.childs,vbox);
                wg->setLayout(vbox);
                QSpacerItem* v = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
                vbox->addItem(v);
                loayout->addWidget(wg);
            }
        }
    }
}










