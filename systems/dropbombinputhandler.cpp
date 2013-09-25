#include "dropbombinputhandler.hpp"

DropBombInputHandler::DropBombInputHandler(): m_haveToDropBomb(false)
{}

void DropBombInputHandler::setCurrentKey(QBomberMan::KEYS currentKey)
{
    m_haveToDropBomb = (currentKey==QBomberMan::SPACE);
}
#include <QDebug>
void DropBombInputHandler::do_update(Entity& entity, double)
{
    if(!m_haveToDropBomb) return;
    ScreenPosition& position = EntityManager::getComponent<ScreenPosition>(entity);
    qDebug() << "droping a bomb at " << position.pos().x() << ", " << position.pos().y();

    EntityManager::createBomb(position);

    m_haveToDropBomb = false;
}
