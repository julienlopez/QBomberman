#include "lifetimemanager.hpp"

#include <QDebug>

void LifeTimeManager::do_update(EntityManager::EntityId entity, double dt)
{
    LifeTime& lifeTime = EntityManager::getComponent<LifeTime>(entity);
    qDebug() << "do_update(" << dt << ") : " << lifeTime.timeLeft();
    lifeTime.timeLeft() -= dt;
}
