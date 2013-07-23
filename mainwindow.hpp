#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <typedefs.hpp>

#include <boost/signal.hpp>

#include <QMainWindow>

class Screen;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    typedef boost::signal<void (QBomberMan::KEYS)> type_signal_current_key;
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    type_signal_current_key& currentKeyChanged();

private:
    Screen* m_screen;
    QTimer* m_majTimer;
    type_signal_current_key m_currentKeyChanged;

    static constexpr double s_dt = .2;

    void startTimer();

protected:
    void keyPressEvent(QKeyEvent* evt) override;
    void keyReleaseEvent(QKeyEvent* evt) override;

private Q_SLOTS:
    void onMajTimerTimeout();
};

#endif // MAINWINDOW_HPP
