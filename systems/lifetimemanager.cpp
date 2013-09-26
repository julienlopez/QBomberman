#include "lifetimemanager.hpp"

#include <QDebug>

void LifeTimeManager::do_update(Entity& entity, double dt)
{
    LifeTime& lifeTime = EntityManager::getComponent<LifeTime>(entity);
    qDebug() << "do_update(" << dt << ") : " << lifeTime.timeLeft();
    lifeTime.timeLeft() -= dt;
}
