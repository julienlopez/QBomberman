#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/screenposition.hpp>
#include <components/velocity.hpp>

class Physics : public CRTP_System<Physics, ListPolicy>, public RequirementMaker<ScreenPosition>
{
public:
    Physics() = default;

private:
    virtual void do_update(ListPolicy::type_list_entities&& entities, double dt) override;
};

#endif // PHYSICS_HPP
