#include "socket.h"

Socket::Socket(QObject *parent ,QString host ,quint16  port) :
    QObject(parent)
{
        this->host =  host ;
        this->port =  port ;
        qDebug()<<"tcp client -> "<<this->host <<this->port;
        this->tcp_socket = new QTcpSocket(this);

        this->tcp_socket->connectToHost(QHostAddress(this->host),this->port);
        connect(this->tcp_socket,
                SIGNAL(stateChanged(QAbstractSocket::SocketState ) ),
                this,
                SLOT(socketStateChangedEvent(QAbstractSocket::SocketState) )
                );
        connect (this->tcp_socket ,
                 SIGNAL(readyRead()) ,
                 this,
                 SLOT(socketReadData())
                 );
}
QString Socket::getServerInfo() const
{
    return QString("%1:%2").arg(this->host).arg(this->port );
}
QString Socket::getServerAddress() const
{
    return this->host;
}

quint16 Socket::getServerPort() const
{
    return this->port;
}


void Socket::setServerInfo(const QString &host,const quint16 &port)
{
    this->host =  host ;
    this->port =  port ;
}

 void Socket::socketStateChangedEvent(QAbstractSocket::SocketState socketState){
//    qDebug()<<"status changed" <<socketState ;

    switch (socketState ) {
    case QAbstractSocket::UnconnectedState  :
        //may try reconnect
        break;
     case  QAbstractSocket::ConnectedState :
        //can send data
        this->socketSendMessage("hello");
        break;
      case QAbstractSocket::ClosingState  :
        //system shut down ?
        break;
       default :
        break;
    }
 }
void Socket::socketSendMessage(QString msg){
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out<<msg;
    this->tcp_socket->write(block);
}
void Socket::socketReadData(){

    QByteArray block = this->tcp_socket->readAll();
    QString result ;
    result.append(block);
    qDebug()<<"receive ack ->"<<result.count()<<result;
}
