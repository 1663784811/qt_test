#include "vdmenudata.h"

VdMenuData::VdMenuData() {}

VdMenuData::~VdMenuData()
{


}

void VdMenuData::setId(QString id)
{
    this->id =id;
}

void VdMenuData::setName(QString name)
{
    this->name = name;
}

void VdMenuData::setIcon(QString icon)
{
    this->icon = icon;
}

void VdMenuData::setChilds(QVector<VdMenuData> *childs)
{
    this->childs = childs;
}
