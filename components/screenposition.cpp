#include "screenposition.hpp"

ScreenPosition::ScreenPosition(const PointF& pos): m_pos(pos)
{}

ScreenPosition::ScreenPosition(const ScreenPosition&): CRTP_Component<ScreenPosition>()
{}

const PointF& ScreenPosition::pos() const
{
    return m_pos;
}

void ScreenPosition::move(const PointF& d)
{
    m_pos += d;
}
