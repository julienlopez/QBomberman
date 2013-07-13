#ifndef TILEPOSITION_HPP
#define TILEPOSITION_HPP

#include <utils/point.hpp>

#include "crtp_component.hpp"

class TilePosition : public CRTP_Component<TilePosition>
{
public:
    TilePosition();
    TilePosition(const TilePosition&);

private:
    PointF m_pos;
};

#endif // TILEPOSITION_HPP
