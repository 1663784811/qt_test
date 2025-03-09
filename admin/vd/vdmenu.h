#ifndef VDMENU_H
#define VDMENU_H

#include <QWidget>
#include <QVector>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include "vd/vdmenudata.h"
#include "vd/vdmenuitem.h"

class VdMenu : public QWidget
{
    Q_OBJECT
public:
    explicit VdMenu(QWidget *parent = nullptr);
    // 设置数据
    void setData(QVector<VdMenuData>* data );

private:
    void updateData(QVector<VdMenuData> *data, QVBoxLayout* loayout); // 更新数据

    QVBoxLayout* vbMenuLayout;
    QSpacerItem* vbLastItem;

    QMap<QString, VdMenuItem> aa; // item
    QMap<QString, int> animation; // 动画
    QString action; // 选中




signals:
    void selectItem();




};

#endif
