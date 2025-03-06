#ifndef VDMENUITEM_H
#define VDMENUITEM_H

#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include "vdmenudata.h"

class VdMenuItem : public QWidget
{
    Q_OBJECT
public:
    explicit VdMenuItem(VdMenuData* menuData, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void selectItem(QString id);


private:
};

#endif // VDMENUITEM_H
