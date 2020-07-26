//
// Created by mortie on 7/26/20.
//
#include "serverinterface.h"

#include <QNetworkReply>

ServerInterface::ServerInterface(QObject *parent)
    : QObject(parent)
    , manager(new QNetworkAccessManager(this))
{

}
ServerInterface::~ServerInterface() {
}
QNetworkReply *ServerInterface::requestListOfStocks() {
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.tsetmc.com/Loader.aspx?ParTree=111C1417"));

    qDebug() << "send a request to get all stocks";

    return manager->get(request);
}
