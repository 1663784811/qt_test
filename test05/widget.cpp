#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    // 连接服务器
    QObject::connect(socket, &QTcpSocket::connected, this, onConnected);
    connect(socket, &QTcpSocket::readyRead, this, onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, onDisconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, onError);

    qDebug() << "Connecting to server...";
    socket->connectToHost("127.0.0.1", 12345); // 连接到服务器
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_startBtn_clicked()
{
    if(!socket->isOpen()){
        ui->startBtn->setDisabled(true);
        ui->startBtn->setText("启动中...");
        ui->ipEdit->setDisabled(true);
        ui->portEdit->setDisabled(true);
        //===
        socket->connectToHost("127.0.0.1", 12345); // 连接到服务器
        ui->startBtn->setText("关闭");
        ui->startBtn->setDisabled(false);
    }else{
        socket->close();
        ui->startBtn->setDisabled(false);
        ui->startBtn->setText("启动");
        ui->ipEdit->setDisabled(false);
        ui->portEdit->setDisabled(false);
    }
}

void Widget::onConnected()
{
    qDebug() << "Connected to server!";
    socket->write("Hello from client\n"); // 发送数据
}

void Widget::onReadyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << "Received from server:" << data;
}

void Widget::onDisconnected()
{
    qDebug() << "Disconnected from server";
}

void Widget::onError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Error:" << socket->errorString();
}
