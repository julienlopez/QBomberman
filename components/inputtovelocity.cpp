#include "inputtovelocity.hpp"

InputToVelocity::InputToVelocity()
{
    m_map[QBomberMan::UP] = PointF(0, -.1);
    m_map[QBomberMan::DOWN] = PointF(0, .1);
    m_map[QBomberMan::LEFT] = PointF(-.1, 0);
    m_map[QBomberMan::RIGHT] = PointF(.1, 0);
}

InputToVelocity::InputToVelocity(const InputToVelocity& i2v): CRTP_Component<InputToVelocity>(), m_map(i2v.m_map)
{}

PointF InputToVelocity::key2Velocity(QBomberMan::KEYS key) const
{
    type_map::const_iterator i = m_map.find(key);
    if(i == m_map.end()) return PointF();
    return i->second;
}
