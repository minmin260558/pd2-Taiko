#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"\

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = 0);
    ~WelcomeWindow();

private slots:
    void on_start_clicked();
    void on_exit_clicked();

private:
    Ui::WelcomeWindow *ui;
    MainWindow mainwindow;\

};

#endif // WELCOMEWINDOW_H
