#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "game.h"
WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    setFixedSize(970, 740);




}
void WelcomeWindow::on_exit_clicked(){

    QApplication::quit();
}
void WelcomeWindow::on_start_clicked(){
    hide();
    Game *game = new Game(this, &mainwindow, &mainwindow);
    game->setFocus();
    mainwindow.show();
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}
