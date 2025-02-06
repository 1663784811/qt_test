#include "tcpserver.h"



TcpServer::TcpServer()
{

}

TcpServer::~TcpServer()
{

}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    // 使用线程池处理新连接
    QThreadPool::globalInstance()->start([socketDescriptor]() {
        QTcpSocket socket;
        socket.setSocketDescriptor(socketDescriptor);

        qDebug() << "New client:" << socket.peerAddress().toString();

        // 读取数据
        while (socket.waitForReadyRead()) {
            QByteArray data = socket.readAll();
            qDebug() << "Received:" << data;
            socket.write("Message received\n");
        }


        // socket.write();

    });
}

