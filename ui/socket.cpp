#include "socket.h"

Socket::Socket(QObject *parent ,QString host ,quint16  port) :
    QObject(parent)
{
        this->host =  host ;
        this->port =  port ;

        qDebug()<<"udp client -> "<<this->host <<this->port;
        this->hostAddress = new QHostAddress(this->host);
        this->udpSocket = new QUdpSocket(this);
        if( ! this->udpSocket->bind(this->port+1)   ){
            qDebug()<<"udp bind error";
            //QMessageBox::information(this,"error","bind fail");
            return ;
        }



        connect (this->udpSocket ,
                 SIGNAL(readyRead()) ,
                 this,
                 SLOT(socketReadData())
                 );

        this->socketSendMessage("hello udp ");



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


void Socket::socketSendMessage(QString msg){
    QByteArray data = msg.toUtf8();
    this->udpSocket->writeDatagram(data,data.size(), *this->hostAddress,this->port);
}
void Socket::socketReadData(){

   if ( !  this->udpSocket->hasPendingDatagrams() )
       return;
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());//设置字符数组的大小 返回第一次监听数 据大小
    udpSocket->readDatagram(datagram.data(),datagram.length());//读数据
    QString message = datagram.data();//把数据转换成字符串
    qDebug()<<"receive ->"<<message;
}
