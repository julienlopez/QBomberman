#include "movement.hpp"
#include <components/velocity.hpp>
#include <components/screenposition.hpp>
#include <entitymanager.hpp>

Movement::Movement()
{
}

void Movement::do_update(Entity& entity, double dt)
{
    Velocity& v = EntityManager::getComponent<Velocity>(entity);
    ScreenPosition& pos = EntityManager::getComponent<ScreenPosition>(entity);
    if(v.m_vector == PointF()) return;
    pos.move(v.m_vector*dt);
}
