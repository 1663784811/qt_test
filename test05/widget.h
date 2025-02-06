#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startBtn_clicked();
    void onConnected();
    void onReadyRead();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);


private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};
#endif // WIDGET_H
