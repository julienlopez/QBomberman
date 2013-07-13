#include "movement.hpp"

Movement::Movement()
{
}

Movement::type_key Movement::requirement() const
{
    return makeRequirement();
}

void Movement::do_update(Entity& entity, double dt)
{

}
