#include "mainwindow.hpp"
#include "screen.hpp"

#include "systems/systemmanager.hpp"

#include <QVBoxLayout>
#include <QTimer>

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

    SystemManager::addTileDisplaySystem(m_screen);

    m_majTimer = new QTimer(this);
    m_majTimer->setInterval(s_dt);
    connect(m_majTimer, SIGNAL(timeout()), this, SLOT(onMajTimerTimeout()));
    m_majTimer->start();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::onMajTimerTimeout()
{
    QTime t = QTime::currentTime();
    SystemManager::update(s_dt);
    m_screen->update();
    qDebug() << t.msecsTo(QTime::currentTime()) << "ms to update";
}
