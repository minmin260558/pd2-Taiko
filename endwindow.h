#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QMainWindow>
#include "welcomewindow.h"
#include "mainwindow.h"
#include "game.h"
namespace Ui {
class EndWindow;
}

class EndWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EndWindow(WelcomeWindow *welcome_window, MainWindow *main_window, Game *oldgame,int score,QWidget *parent = 0);
    ~EndWindow();

private slots:
    void on_quit_clicked();
    void on_restart_clicked();

private:
    Ui::EndWindow *ui;
    WelcomeWindow *welcomewindow;
    MainWindow *mainwindow;
    Game *game;
};

#endif // ENDWINDOW_H
