//
// Created by mortie on 7/26/20.
//

#ifndef SERVERINTERFACE_H
#define SERVERINTERFACE_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

class ServerInterface : public QObject{
    Q_OBJECT

public:
    explicit ServerInterface(QObject *parent = nullptr);
    ~ServerInterface() override;

    QNetworkReply *requestListOfStocks();

private:
    QNetworkAccessManager *manager;
};

#endif//SERVERINTERFACE_H
