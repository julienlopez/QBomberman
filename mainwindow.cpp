#include "mainwindow.hpp"
#include "screen.hpp"

#include <systems/systemmanager.hpp>
#include <systems/movementinputhandler.hpp>
#include <systems/dropbombinputhandler.hpp>

#include <QVBoxLayout>
#include <QTimer>
#include <QKeyEvent>

#include <QDebug>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    m_screen = new Screen;
    layout->addWidget(m_screen);

    QWidget* w = new QWidget;
    w->setLayout(layout);
    setCentralWidget(w);

    SystemManager::addScreenDisplaySystem(m_screen);

    MovementInputHandler* movementInputHandler = new MovementInputHandler;
    currentKeyChanged().connect(std::bind(&MovementInputHandler::setCurrentKey, movementInputHandler, std::placeholders::_1));
    SystemManager::add(SystemManager::up_system(movementInputHandler));

    DropBombInputHandler* dropBombInputHandler = new DropBombInputHandler;
    currentKeyChanged().connect(std::bind(&DropBombInputHandler::setCurrentKey, dropBombInputHandler, std::placeholders::_1));
    SystemManager::add(SystemManager::up_system(dropBombInputHandler));

    SystemManager::addMovementSystem();
    SystemManager::addPhysicsSystem();
    SystemManager::addLifeTimeManager();
    SystemManager::addBombTrigger();

    startTimer();
}

MainWindow::~MainWindow()
{}

MainWindow::type_signal_current_key& MainWindow::currentKeyChanged()
{
    return m_currentKeyChanged;
}

void MainWindow::startTimer() {
    m_majTimer = new QTimer(this);
    m_majTimer->setInterval(s_dt*1000);
    connect(m_majTimer, SIGNAL(timeout()), this, SLOT(onMajTimerTimeout()));
    m_majTimer->start();
}

namespace
{
    QBomberMan::KEYS convertKey(QKeyEvent* evt)
    {
//        QString keyAsHex = QString("%1").arg(evt->key(), 0, 16);
//        qDebug() << keyAsHex;
        switch(evt->key())
        {
            case Qt::Key_Up: return QBomberMan::UP;
            case Qt::Key_Down: return QBomberMan::DOWN;
            case Qt::Key_Left: return QBomberMan::LEFT;
            case Qt::Key_Right: return QBomberMan::RIGHT;
            case Qt::Key_Space: return QBomberMan::SPACE;
            default: return QBomberMan::NONE;
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent* evt)
{
//    qDebug() << "MainWindow::keyPressEvent()";
    currentKeyChanged()(convertKey(evt));
}

void MainWindow::keyReleaseEvent(QKeyEvent* evt)
{
//    qDebug() << "MainWindow::keyReleaseEvent()";
    Q_UNUSED(evt);
    currentKeyChanged()(QBomberMan::NONE);
}

void MainWindow::onMajTimerTimeout()
{
//    QTime t = QTime::currentTime();
    m_screen->resetImage();
    SystemManager::update(s_dt);
    m_screen->update();
//    qDebug() << t.msecsTo(QTime::currentTime()) << "ms to update";
}
