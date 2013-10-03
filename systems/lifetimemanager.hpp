#ifndef LIFETIMEMANAGER_HPP
#define LIFETIMEMANAGER_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/lifetime.hpp>

class LifeTimeManager : public CRTP_System<LifeTimeManager>, public RequirementMaker<LifeTime>
{
public:
    LifeTimeManager() = default;

private:
    virtual void do_update(EntityManager::EntityId entity, double dt) override;
};

#endif // LIFETIMEMANAGER_HPP
