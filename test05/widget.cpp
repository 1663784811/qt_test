#include "widget.h"
#include "ui_widget.h"





Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->ipEdit->setText("192.168.0.130");
    QIntValidator *validator = new QIntValidator(0, 65535, this);
    ui->portEdit->setValidator(validator);
    ui->portEdit->setText("8090");



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
    if(!socket->isOpen()){
        ui->startBtn->setDisabled(true);
        ui->startBtn->setText("启动中...");
        ui->ipEdit->setDisabled(true);
        ui->portEdit->setDisabled(true);
        // 连接到服务器
        QString ip = ui->ipEdit->text();
        quint16 port = ui->portEdit->text().toUShort();
        socket->connectToHost(ip, port);
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
    ui->startBtn->setDisabled(false);
    ui->startBtn->setText("关闭");
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
