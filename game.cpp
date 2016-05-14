#include <QPainter>
#include "game.h"
#include "endwindow.h"
Game::Game(WelcomeWindow *welcome_window, MainWindow *main_window, QWidget *parent):
    QWidget(parent)
{
    setFixedSize(1380, 850);
    this->welcomewindow = welcome_window;
    this->mainwindow = main_window;
    sec = 30;
    timespace = 0;
    score = 0;
    balls.push_back(new Ball(1300,600));

    movetmr = new QTimer(this);
    movetmr->start(1000/60);   // 60fps
    QObject::connect(movetmr, SIGNAL(timeout()),this, SLOT(RefreshPosition()));

    gentmr = new QTimer(this);
    gentmr->start(1000);
    QObject::connect(gentmr,SIGNAL(timeout()),this,SLOT(GenBall()));

}
void Game::RefreshPosition(){
    timespace++;
    if(timespace%60==0){
        if(this->sec<0||this->sec==0){
            movetmr->stop();
            gentmr->stop();
            (new EndWindow(this->welcomewindow, this->mainwindow, this,this->score))->show();

        }
        else
            this->sec--;
        timespace=0;

    }
    for(int i=0;i<balls.size();++i){
        balls[i]->UpdatePosition();

        if(balls[i]->x<-50||balls[i]->x==-50){
            delete balls[i];
            balls.pop_front();
            --i;
        }
    }

    repaint();
}
void Game::paintEvent(QPaintEvent *event)
{
        (void)(event);
        QPainter painter(this);
        for(int i=0;i<balls.size();++i)
            balls.at(i)->PaintBall(painter);
        painter.setPen(Qt::white);
        painter.setFont(QFont(QString::fromLocal8Bit("Arial"),15,QFont::Bold));
        painter.drawText(550,180,"Time:");
        painter.drawText(650,180,QString::number(this->sec));
        painter.drawText(720,180,"Score:");
        painter.drawText(820,180,QString::number(this->score));

}
void Game::GenBall(){
    balls.push_back(new Ball(1300,600));
}

void Game::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_M){
        if(balls[0]->x>50&&balls[0]->x<130&&balls[0]->type==1){
            delete balls[0];
            balls.pop_front();
            ++score;
        }
    }
    event->accept();
    if(event->key()==Qt::Key_C){
        if(balls[0]->x>50&&balls[0]->x<130&&balls[0]->type==0){
            delete balls[0];
            balls.pop_front();
            ++score;
        }
    }
    event->accept();
}

Game::~Game(){

    delete movetmr;
    delete gentmr;
    for(int i=0;i<balls.size();++i)
        delete balls[i];
}
