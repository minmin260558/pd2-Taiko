#include "endwindow.h"
#include "ui_endwindow.h"
#include <QPainter>
EndWindow::EndWindow(WelcomeWindow *welcome_window, MainWindow *main_window, Game *oldgame,int score,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndWindow)
{
    ui->setupUi(this);
    setFixedSize(1024,683);
    this->welcomewindow = welcome_window;
    this->mainwindow = main_window;
    this->game = oldgame;
    ui->getscore->setText(QString::number(score));

}

EndWindow::~EndWindow()
{
    delete ui;
}
void EndWindow::on_quit_clicked()
{
    QApplication::quit();
}
void EndWindow::on_restart_clicked()
{
    mainwindow->hide();
    welcomewindow->show();
    delete game;

    close();
}
