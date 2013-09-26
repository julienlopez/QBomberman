#include "bombtrigger.hpp"

#include <QDebug>

void BombTrigger::do_update(Entity& entity, double)
{
    LifeTime& lifeTime = EntityManager::getComponent<LifeTime>(entity);
    if(lifeTime.isDead()) {
        qDebug() << "bomb exploded";
        EntityManager::scheduleToRemoveEntity(entity);
    }
}
