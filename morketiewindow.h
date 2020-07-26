//
// Created by mortie on 7/26/20.
//

#ifndef MORKETIE_MORKETIEWINDOW_H
#define MORKETIE_MORKETIEWINDOW_H

#include <QMainWindow>

namespace Ui{
    class MorketieForm;
}

class MorketieWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MorketieWindow(QWidget *parent = nullptr);
    ~MorketieWindow() override;

private:
    Ui::MorketieForm *ui;
};

#endif //MORKETIE_MORKETIEWINDOW_H
