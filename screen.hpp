#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <QWidget>
#include <QPainter>

class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = 0);

    void resetImage();
    void finalizeImage();
    void addTile(const std::string& fileName, int x, int y);

protected:
    virtual void paintEvent(QPaintEvent * evt);

private:
    typedef quint16 type_size;
    type_size m_largeur;
    type_size m_hauteur;

    typedef QPair<QPoint, QPixmap> type_pair_tile;
    QList<type_pair_tile> m_tiles;

    void printGrid(QPainter& p) const;
    
signals:
    
public slots:
    
};

#endif // SCREEN_HPP
