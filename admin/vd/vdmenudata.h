#ifndef VDMENUDATA_H
#define VDMENUDATA_H
#include <QString>
#include <QVector>


class VdMenuData
{
public:
    VdMenuData();
    ~VdMenuData();

    QString id;
    QString name;
    QString icon;
    QVector<VdMenuData>* childs;


private:

};

#endif // VDMENUDATA_H
