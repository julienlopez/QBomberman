#ifndef INPUTTOVELOCITY_HPP
#define INPUTTOVELOCITY_HPP

#include "crtp_component.hpp"
#include <utils/point.hpp>

#include <map>

class InputToVelocity : public CRTP_Component<InputToVelocity>
{
public:
    InputToVelocity();
    InputToVelocity(const InputToVelocity& i2v);

    PointF key2Velocity(QBomberMan::KEYS key) const;

private:
    typedef std::map<QBomberMan::KEYS, PointF> type_map;
    type_map m_map;
};

#endif // INPUTTOVELOCITY_HPP
