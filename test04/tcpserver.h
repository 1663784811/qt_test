#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>

class TcpServer : public QTcpServer{
    Q_OBJECT

public:
    TcpServer();
    ~TcpServer();

protected:
    // 新连接进来
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    // 读取数据
    void onReadyRead();
    // 关闭连接
    void onDisconnected();

private:
     // 缓存每个客户端的数据
    QMap<QTcpSocket*, QByteArray> bufferMap;
    void processData(QTcpSocket *clientSocket);
};

#endif // TCPSERVER_H
