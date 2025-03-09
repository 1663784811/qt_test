#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>

#include "widget/testbtnwidget.h"
#include "ui_widget.h"
#include "vd/vdmenu.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class mainWin;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void selectMenu();

private:
    Ui::mainWin *ui;
    TestBtnWidget* btnWidget;

    QVector<VdMenuData> *menuData;

    QMap<QString, QWidget*> widgetList;
    QMap<QString, int> widgetIndex;




};
#endif // WIDGET_H
