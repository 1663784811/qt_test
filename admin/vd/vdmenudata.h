#ifndef VDMENUDATA_H
#define VDMENUDATA_H
#include <QString>
#include <QVector>


class VdMenuData
{
public:
    VdMenuData();
    ~VdMenuData();

    void setId(QString id);
    void setName(QString name);
    void setIcon(QString icon);
    void setChilds(QVector<VdMenuData>* childs);

private:
    QString id;
    QString name;
    QString icon;
    QVector<VdMenuData>* childs;
};

#endif // VDMENUDATA_H
