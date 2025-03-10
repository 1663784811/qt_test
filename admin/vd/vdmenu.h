#ifndef VDMENU_H
#define VDMENU_H

#include <QWidget>
#include <QVector>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include "vd/vdmenudata.h"
#include "vd/vdmenuitem.h"
#include "vd/data/vdmenutree.h"


class VdMenu : public QWidget
{
    Q_OBJECT
public:
    explicit VdMenu(QWidget *parent = nullptr);
    // 设置数据
    void setData(QVector<VdMenuData>* data );

private:
    QVBoxLayout* vbMenuLayout;
    QSpacerItem* vbLastItem;

    QString action; // 选中


    QMap<QString,VdMenuTree> root;
    QPropertyAnimation *animation;
      bool expanded = false;
signals:
    void selectItem();





private:
    void updateData(QVector<VdMenuData> *data, QVBoxLayout* loayout, int level =0, VdMenuTree *prt = nullptr); // 更新数据



};

#endif
