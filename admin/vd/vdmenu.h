#ifndef VDMENU_H
#define VDMENU_H

#include <QWidget>
#include <QVector>
#include <QVBoxLayout>
#include <vd/vdmenudata.h>

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



signals:
    void selectItem();




};

#endif
