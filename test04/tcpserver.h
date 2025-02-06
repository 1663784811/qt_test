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

private:
    void incomingConnection(qintptr socketDescriptor) override;




};

#endif // TCPSERVER_H
