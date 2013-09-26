#include "dropbombinputhandler.hpp"

DropBombInputHandler::DropBombInputHandler(): m_haveToDropBomb(false)
{}

void DropBombInputHandler::setCurrentKey(QBomberMan::KEYS currentKey)
{
    m_haveToDropBomb = (currentKey==QBomberMan::SPACE);
}

void DropBombInputHandler::do_update(Entity& entity, double)
{
    if(!m_haveToDropBomb) return;
    ScreenPosition& position = EntityManager::getComponent<ScreenPosition>(entity);
    EntityManager::createBomb(position, 5);
    m_haveToDropBomb = false;
}
