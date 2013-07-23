#include "tiledisplay.hpp"
#include "screen.hpp"
#include "entitymanager.hpp"

TileDisplay::TileDisplay(Screen* screen): m_screen(screen)
{}

void TileDisplay::do_update(Entity& entity, double)
{
    if(!m_screen) return;
    Graphic& g = EntityManager::getComponent<Graphic>(entity);
    TilePosition& pos = EntityManager::getComponent<TilePosition>(entity);
    m_screen->addTile(g.fileName(), pos.x(), pos.y());
}
