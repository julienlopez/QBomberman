#include "movement.hpp"

#include <components/screenposition.hpp>
#include <components/velocity.hpp>

Movement::Movement()
{
}

Movement::type_key Movement::requirement() const
{
    return makeRequirement();
}

Movement::type_key Movement::makeRequirement()
{
    return ScreenPosition::s_key | Velocity::s_key;
}

void Movement::do_update(Entity& entity, double dt)
{

}
