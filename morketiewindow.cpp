//
// Created by mortie on 7/26/20.
//

#include "morketiewindow.h"
#include "ui_morketiewindow.h"

#include <QNetworkReply>
#include <iostream>

#include "serverinterface.h"
#include "htmlcxx/html/ParserDom.h"

using namespace htmlcxx;
using namespace std;

#include <QDebug>

MorketieWindow::MorketieWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MorketieForm)
{
    ui->setupUi(this);

    auto *serverInterface = new ServerInterface(this);
    reply = serverInterface->requestListOfStocks();
    connect(reply, &QNetworkReply::finished, this, &MorketieWindow::analyzeReply);
}

MorketieWindow::~MorketieWindow() {
}

void MorketieWindow::analyzeReply() {
    QMap<long, QString> stockList;

    QString html = reply->readAll();

    HTML::ParserDom parser;
    tree<HTML::Node> dom = parser.parseTree(html.toStdString());

    //Dump all nodes in the tree
    tree<HTML::Node>::iterator it = dom.begin();
    tree<HTML::Node>::iterator end = dom.end();
    for (; it != end; ++it)
    {
        it->parseAttributes();
        if(!it->attribute("id").second.compare("tblToGrid")) {
            tree<HTML::Node>::iterator tit = it.begin();
            tree<HTML::Node>::iterator tend = it.end();

            for (; tit != tend; ++tit) {
                tit->parseAttributes();

                if (tit->tagName() == "a") {
                    QString stockName = tit->text().c_str();
                    QString stockHref = tit->attribute("href").second.c_str();
                    stockHref = stockHref.right(stockHref.indexOf("=") - 2);
                    qDebug()<< "href: "<<stockHref << "-" << stockName;
                    stockList.insert(stockHref.toLong(), stockName);
                }
            }
        }
    }

    QMapIterator<long, QString> i(stockList);
    while(i.hasNext()) {
        i.next();
        ui->stocksList->addItem(QString::number(i.key()));
    }
}
