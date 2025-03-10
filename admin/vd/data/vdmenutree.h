#ifndef VDMENUTREE_H
#define VDMENUTREE_H

#include <QString>
#include <QPropertyAnimation>
#include "vd/vdmenuitem.h"

/**
 * 菜单树
 */
class VdMenuTree
{
public:
    VdMenuTree(){}

    QString key;    //  节点Key
    VdMenuTree *prt; // 父节点
    VdMenuItem *item; // 当前节点
    QPropertyAnimation *animation; // 节点动画
};

#endif // VDMENUTREE_H
