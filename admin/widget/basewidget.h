#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>

class BaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWidget(QWidget *parent = nullptr);

protected:
    void setLayout(QLayout * layout);

private:
    QVBoxLayout* boxLayout;
    QScrollArea *mainScroll;
    QWidget* wd;

signals:


};

#endif // BASEWIDGET_H
