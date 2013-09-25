#include "movementinputhandler.hpp"
#include <entitymanager.hpp>

MovementInputHandler::MovementInputHandler()
{
    m_map[QBomberMan::UP] = PointF(0, -.1);
    m_map[QBomberMan::DOWN] = PointF(0, .1);
    m_map[QBomberMan::LEFT] = PointF(-.1, 0);
    m_map[QBomberMan::RIGHT] = PointF(.1, 0);
}

void MovementInputHandler::setCurrentKey(QBomberMan::KEYS currentKey)
{
    m_currentKey = currentKey;
}

void MovementInputHandler::do_update(Entity& entity, double)
{
    Velocity& v = EntityManager::getComponent<Velocity>(entity);
    v.m_vector = key2Velocity(m_currentKey);
}

PointF MovementInputHandler::key2Velocity(QBomberMan::KEYS key) const
{
    type_map::const_iterator i = m_map.find(key);
    if(i == m_map.end()) return PointF();
    return i->second;
}
