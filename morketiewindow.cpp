//
// Created by mortie on 7/26/20.
//

#include "morketiewindow.h"
#include "ui_morketiewindow.h"

MorketieWindow::MorketieWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MorketieForm)
{
    ui->setupUi(this);
}
MorketieWindow::~MorketieWindow() {
}
