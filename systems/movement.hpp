#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/screenposition.hpp>
#include <components/velocity.hpp>

class Movement : public CRTP_System<Movement>, public RequirementMaker<ScreenPosition, Velocity>
{
public:
    Movement();

    virtual type_key requirement() const override;

private:
    virtual void do_update(Entity& entity, double dt) override;
};

#endif // MOVEMENT_HPP
