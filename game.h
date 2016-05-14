#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QTimer>
#include "welcomewindow.h"
#include "mainwindow.h"
#include "ball.h"
class Game : public QWidget
{
    Q_OBJECT

public:
    Game(WelcomeWindow *welcome_window, MainWindow *main_window, QWidget *parent = 0);
    int score;
    ~Game();
public slots:
    void RefreshPosition();
    void GenBall();
protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    WelcomeWindow *welcomewindow;
    MainWindow *mainwindow;
    QTimer *movetmr;
    QTimer *gentmr;
    int sec;
    int timespace;
    QList<Ball*> balls;
    void keyPressEvent(QKeyEvent *event);
};
#endif // GAME_H
