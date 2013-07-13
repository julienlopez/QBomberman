#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "crtp_system.hpp"

class Movement : public CRTP_System<Movement>
{
public:
    Movement();

    virtual type_key requirement() const override;

    static type_key makeRequirement();

private:
    virtual void do_update(Entity& entity, double dt) override;
};

#endif // MOVEMENT_HPP
