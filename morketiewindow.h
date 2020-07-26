//
// Created by mortie on 7/26/20.
//

#ifndef MORKETIE_MORKETIEWINDOW_H
#define MORKETIE_MORKETIEWINDOW_H

#include <QMainWindow>

class QNetworkReply;

namespace Ui{
    class MorketieForm;
}

class MorketieWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MorketieWindow(QWidget *parent = nullptr);
    ~MorketieWindow() override;

private slots:
    void analyzeReply();

private:
    Ui::MorketieForm *ui;

    QNetworkReply *reply;
};

#endif //MORKETIE_MORKETIEWINDOW_H
