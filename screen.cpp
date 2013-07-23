#include "screen.hpp"

Screen::Screen(QWidget *parent) :
    QWidget(parent), m_largeur(11), m_hauteur(11)
{
    setMinimumSize(800, 800);

    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::white);
    setPalette(p);

    setAutoFillBackground(true);
}

void Screen::resetImage()
{
    m_tiles.clear();
    m_objects.clear();
}

void Screen::finalizeImage()
{

}

void Screen::addTile(const std::string& fileName, int x, int y)
{
    m_tiles.push_back(type_pair_tile(QPoint(x, y), QPixmap(QString::fromStdString(fileName))));
}

void Screen::addObject(const std::string& fileName, double x, double y)
{
    m_objects.push_back(type_pair_object(QPointF(x, y), QPixmap(QString::fromStdString(fileName))));
}
#include <QDebug>
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

    for(const type_pair_tile& tile : m_tiles)
    {
        p.drawPixmap(tile.first.x(), tile.first.y(), 1, 1, tile.second);
    }

    for(const type_pair_object& object : m_objects)
    {
        QPixmap pix = object.second;
        QPointF pos(object.first.x() - 0.5, object.first.y() - 0.5);
        p.drawPixmap(QRectF(pos, QSizeF(1, 1)), pix, QRectF(QPointF(0,0),QSizeF(256,256)));
    }

    printGrid(p);
}

void Screen::printGrid(QPainter& p) const
{
    for(type_size i = 0; i < m_largeur; i++)
        p.drawLine(QPoint(i, 0), QPoint(i, m_hauteur));

    for(type_size i = 0; i < m_hauteur; i++)
        p.drawLine(QPoint(0, i), QPoint(m_largeur, i));
}
