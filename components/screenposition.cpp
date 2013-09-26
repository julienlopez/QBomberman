#include "screenposition.hpp"

ScreenPosition::ScreenPosition(const PointF& pos): m_pos(pos)
{}

ScreenPosition::ScreenPosition(const ScreenPosition& p): CRTP_Component<ScreenPosition>(), m_pos(p.m_pos)
{}

const PointF& ScreenPosition::pos() const
{
    return m_pos;
}

void ScreenPosition::move(const PointF& d)
{
    m_pos += d;
}
