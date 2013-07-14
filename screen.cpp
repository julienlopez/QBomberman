#include "screen.hpp"

#include <QPainter>

Screen::Screen(QWidget *parent) :
    QWidget(parent), m_largeur(10), m_hauteur(10)
{
    setMinimumSize(800, 800);

    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::white);
    setPalette(p);

    setAutoFillBackground(true);
}

void Screen::paintEvent(QPaintEvent * evt)
{
    Q_UNUSED(evt);

    QPainter p(this);
    QPen pen = p.pen();
    pen.setWidth(.1);
    p.setPen(pen);

    p.drawLine(QPoint(0, height()-1), QPoint(width(), height()-1));
    p.drawLine(QPoint(width()-1, 0), QPoint(width()-1, height()));

    p.scale((double)width()/m_largeur, (double)height()/m_hauteur);

    printGrid(p);
}

void Screen::printGrid(QPainter& p) const
{
    for(type_size i = 0; i < m_largeur; i++)
        p.drawLine(QPoint(i, 0), QPoint(i, m_hauteur));

    for(type_size i = 0; i < m_hauteur; i++)
        p.drawLine(QPoint(0, i), QPoint(m_largeur, i));
}
