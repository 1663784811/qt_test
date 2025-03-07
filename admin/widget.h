#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "widget/testbtnwidget.h"

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


    QMap<QString, QWidget*> widgetList;
    QMap<QString, int> widgetIndex;


};
#endif // WIDGET_H
