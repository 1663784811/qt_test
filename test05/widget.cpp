#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    // 连接服务器
    connect(socket, &QTcpSocket::connected, this, &Widget::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &Widget::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Widget::onDisconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, &Widget::onError);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_startBtn_clicked()
{
    QString ip = ui->ipEdit->text();
    QString portStr = ui->portEdit->text();
    if(!socket->isOpen()){
        ui->startBtn->setDisabled(true);
        ui->startBtn->setText("启动中...");
        ui->ipEdit->setDisabled(true);
        ui->portEdit->setDisabled(true);
        // 连接到服务器
        socket->connectToHost("127.0.0.1", 12345);
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




    // 发送数据
    socket->write("Hello from client\n");
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
    qDebug() << "Error:" << socket->errorString() << socketError;
    socket->close();
    ui->startBtn->setDisabled(false);
    ui->startBtn->setText("启动");
    ui->ipEdit->setDisabled(false);
    ui->portEdit->setDisabled(false);
}
