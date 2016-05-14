#ifndef BALL_H
#define BALL_H
#include <QObject>
#include <QPixmap>
#include <QPainter>
#include <QMainWindow>
class Ball : public QObject{

    Q_OBJECT

public:
    Ball(int _x, int _y): x(_x), y(_y), vx(5) {

        int n = qrand()%2;
        if(n==1){
           pic.load(":/pics/mikasa.png");
           type = n;
        }
        else{
           pic.load(":/pics/conti.png");
           type = n;
        }
    }
    ~Ball(){
    }
    void UpdatePosition() {
         x = x - vx;
         emit PositionChange(x, y);
    }
    void PaintBall(QPainter &painter) {
        painter.drawPixmap(x, y, pic);
    }

    int x,y;
    int type;
signals:
    void PositionChange(int, int);
private:
    QPixmap pic;
    int vx; // velocity

};

#endif // BALL_H
