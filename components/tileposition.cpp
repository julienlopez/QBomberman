#include "tileposition.hpp"

TilePosition::TilePosition(const Point& pos): m_pos(pos)
{}

TilePosition::TilePosition(const TilePosition&): CRTP_Component<TilePosition>()
{}

int TilePosition::x() const
{
    return m_pos.x();
}

int TilePosition::y() const
{
    return m_pos.y();
}
