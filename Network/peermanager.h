#ifndef PEERMANAGER_H
#define PEERMANAGER_H

#include <QByteArray>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QUdpSocket>
#include <QtNetwork>
#include "client.h"
#include "connection.h"

class Client;
class Connection;

class PeerManager : public QObject
{
    Q_OBJECT

public:
    PeerManager(Client *client);

    void setServerPort(int port);
    void startBroadcasting();
    bool isLocalHostAddress(const QHostAddress &address);
    QByteArray getAddress() const;
    QList<QHostAddress> getBroadcastAddresses() const;
    QList<QHostAddress> getIPAddresses() const;

signals:
    void newConnection(Connection *connection);

private slots:
    void sendBroadcastDatagram();
    void readBroadcastDatagram();

private:
    void updateAddresses();

    Client *client;
    QList<QHostAddress> broadcastAddresses;
    QList<QHostAddress> ipAddresses;
    QUdpSocket broadcastSocket;
    QTimer broadcastTimer;
    QByteArray address;
    int serverPort;
};

#endif
