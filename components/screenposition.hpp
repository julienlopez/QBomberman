#ifndef SCREENPOSITION_HPP
#define SCREENPOSITION_HPP

#include <utils/point.hpp>

#include "crtp_component.hpp"

class ScreenPosition : public CRTP_Component<ScreenPosition>
{
public:
    ScreenPosition(const PointF& pos = PointF());
    ScreenPosition(const ScreenPosition&);

    const PointF& pos() const;

    void move(const PointF& d);

private:
    PointF m_pos;
};

#endif // SCREENPOSITION_HPP
