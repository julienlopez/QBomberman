#ifndef LIFETIME_HPP
#define LIFETIME_HPP

#include "crtp_component.hpp"

class LifeTime : public CRTP_Component<LifeTime>
{
public:
    LifeTime(double lifeTime = 0);
    LifeTime(const LifeTime& l);

    double& timeLeft();

    bool isDead() const;

private:
    double m_timeLeft;
};

#endif // LIFETIME_HPP
