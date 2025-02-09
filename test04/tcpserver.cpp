#include "tcpserver.h"


TcpServer::TcpServer()
{

}

TcpServer::~TcpServer()
{

}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *clientSocket = new QTcpSocket(this);
    clientSocket->setSocketDescriptor(socketDescriptor);
    // 绑定事件
    connect(clientSocket, &QTcpSocket::readyRead, this, &TcpServer::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &TcpServer::onDisconnected);
    qDebug() << "New client connected: " << clientSocket->peerAddress().toString();
}

void TcpServer::onReadyRead()
{
    qDebug() << "读取数据";
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;
    bufferMap[clientSocket].append(clientSocket->readAll());
    processData(clientSocket);
}

void TcpServer::onDisconnected()
{
    qDebug() << "关闭连接";
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;
    bufferMap.remove(clientSocket);
    clientSocket->deleteLater();
}

void TcpServer::processData(QTcpSocket *clientSocket) {
    QByteArray &buffer = bufferMap[clientSocket];
    while (true) {
        // 先检查是否收到4字节长度信息
        if (buffer.size() < static_cast<int>(sizeof(quint32))) return;
        QDataStream stream(&buffer, QIODevice::ReadOnly);
        stream.setByteOrder(QDataStream::BigEndian);

        quint32 dataSize;
        // 读取数据长度
        stream >> dataSize;
        // 数据不完整，等待更多数据
        if (buffer.size() < static_cast<int>(sizeof(quint32) + dataSize)) return;
        // 提取完整数据
        QByteArray data = buffer.mid(sizeof(quint32), dataSize);
        // 移除已处理的数据
        buffer.remove(0, sizeof(quint32) + dataSize);
        qDebug() << "Received complete data:" << QString::fromUtf8(data);
    }
}
