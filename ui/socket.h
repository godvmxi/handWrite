#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QUdpSocket>
#include <QString>
 #include <QHostAddress>
#include <QTimer>
#include <QMessageBox>

class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(QObject *parent = 0,QString host="127.0.0.1",quint16 port=20000);

    QString getServerInfo() const;
    QString getServerAddress() const ;
    quint16  getServerPort() const;
    void setServerInfo(const QString &host,const quint16 &port);

signals:
    void socketReceiveData(QString msg);
private slots :
    void socketStateChangedEvent(QAbstractSocket::SocketState socketState);
    void socketReadData();
public slots:
//    void socketDisconnectEvent();
//    void socketConnectEvent();

    void socketSendMessage(QString msg);

private :
        QUdpSocket *udpSocket ;
        QString host;
        quint16 port;
        QHostAddress * hostAddress ;
        QTimer *timer ;

};

#endif // SOCKET_H
