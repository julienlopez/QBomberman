#include "mainwindow.hpp"
#include "screen.hpp"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    m_screen = new Screen;
    layout->addWidget(m_screen);

    QWidget* w = new QWidget;
    w->setLayout(layout);
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{
    
}
