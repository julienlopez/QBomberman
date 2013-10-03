#include "explosionimpact.hpp"

ExplosionImpact::ExplosionImpact(ExplosionBarrier t): m_type(t)
{}

ExplosionImpact::ExplosionImpact(const ExplosionImpact& ei): CRTP_Component<ExplosionImpact>(), m_type(ei.m_type)
{}

ExplosionImpact::ExplosionBarrier ExplosionImpact::type() const
{
    return m_type;
}
