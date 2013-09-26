#include "lifetime.hpp"

LifeTime::LifeTime(double lifeTime): m_timeLeft(lifeTime)
{}

LifeTime::LifeTime(const LifeTime& l): CRTP_Component<LifeTime>(), m_timeLeft(l.m_timeLeft)
{}

double& LifeTime::timeLeft()
{
    return m_timeLeft;
}

bool LifeTime::isDead() const
{
    return m_timeLeft <= 0;
}
