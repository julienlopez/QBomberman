#ifndef SCREENPOSITION_HPP
#define SCREENPOSITION_HPP

#include <utils/point.hpp>

#include "crtp_component.hpp"

class ScreenPosition : public CRTP_Component<ScreenPosition>
{
public:
    ScreenPosition();
    ScreenPosition(const ScreenPosition&);

private:
    PointF m_pos;
};

#endif // SCREENPOSITION_HPP
