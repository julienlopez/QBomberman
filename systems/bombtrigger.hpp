#ifndef BOMBTRIGGER_HPP
#define BOMBTRIGGER_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/lifetime.hpp>

class BombTrigger : public CRTP_System<BombTrigger>, public RequirementMaker<LifeTime>
{
public:
    BombTrigger() = default;

private:
    virtual void do_update(EntityManager::EntityId entity, double dt) override;
};

#endif // BOMBTRIGGER_HPP
