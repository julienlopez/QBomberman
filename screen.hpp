#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <QWidget>

class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent * evt);

private:
    typedef quint16 type_size;
    type_size m_largeur;
    type_size m_hauteur;

    void printGrid(QPainter& p) const;
    
signals:
    
public slots:
    
};

#endif // SCREEN_HPP
