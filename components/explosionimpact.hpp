#ifndef EXPLOSIONIMPACT_HPP
#define EXPLOSIONIMPACT_HPP

#include "crtp_component.hpp"

class ExplosionImpact : public CRTP_Component<ExplosionImpact>
{
public:
    enum ExplosionBarrier
    {
        None = 0, Soft, Hard
    };

    ExplosionImpact(ExplosionBarrier t = None);
    ExplosionImpact(const ExplosionImpact& ei);

    ExplosionBarrier type() const;

private:
    ExplosionBarrier m_type;
};

#endif // EXPLOSIONIMPACT_HPP
