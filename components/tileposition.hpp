#ifndef TILEPOSITION_HPP
#define TILEPOSITION_HPP

#include <utils/point.hpp>

#include "crtp_component.hpp"

class TilePosition : public CRTP_Component<TilePosition>
{
public:
    TilePosition(const Point& pos = Point());
    TilePosition(const TilePosition&);

    int x() const;
    int y() const;

private:
    Point m_pos;
};

#endif // TILEPOSITION_HPP
