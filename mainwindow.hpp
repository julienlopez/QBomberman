#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class Screen;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    Screen* m_screen;
    QTimer* m_majTimer;

    static constexpr double s_dt = .2;

private slots:
    void onMajTimerTimeout();
};

#endif // MAINWINDOW_HPP
