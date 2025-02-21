#include "widget.h"
#include "ui_widget.h"
#include <QTcpServer>
#include <qdebug.h>
#include <QDnsHostAddressRecord>
#include <QHostAddress>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QListWidgetItem>
#include "useritem.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 获取本机IP地址
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for (const QHostAddress &address : list) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && !address.isLoopback()) {
            qDebug() << "IPv4 Address:" << address.toString();
            ui->ipEdit->setText(address.toString());
            break;
        }
    }
    ui->portEdit->setText("8090");
    QIntValidator *validator = new QIntValidator(0, 65535, this);
    ui->portEdit->setValidator(validator);
    tcpServer = new TcpServer;


    for(int i=0;i< 10;i++){
        QListWidgetItem* item = new QListWidgetItem;



        UserItem* useritem = new UserItem(this);
        item->setSizeHint(useritem->sizeHint());
        ui->userlist->addItem(item);
        ui->userlist->setItemWidget(item, useritem);
    }










}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startBtn_clicked()
{
    if(!tcpServer->isListening()){
        ui->startBtn->setDisabled(true);
        ui->startBtn->setText("启动中...");
        ui->ipEdit->setDisabled(true);
        ui->portEdit->setDisabled(true);
        //===
        quint16 port = ui->portEdit->text().toUShort();
        bool isListen = tcpServer->listen(QHostAddress::Any, port);
        if(isListen){
            ui->startBtn->setText("关闭");
            ui->startBtn->setDisabled(false);
        }else{
            ui->startBtn->setDisabled(false);
            ui->startBtn->setText("启动");
            ui->ipEdit->setDisabled(false);
            ui->portEdit->setDisabled(false);
        }
    }else{
        tcpServer->close();
        ui->startBtn->setDisabled(false);
        ui->startBtn->setText("启动");
        ui->ipEdit->setDisabled(false);
        ui->portEdit->setDisabled(false);
    }
}

