#ifndef VELOCITY_HPP
#define VELOCITY_HPP

#include <utils/point.hpp>

#include "crtp_component.hpp"

class Velocity : public CRTP_Component<Velocity>
{
public:
    Velocity();

private:
    PointF m_vector;
};

#endif // VELOCITY_HPP
