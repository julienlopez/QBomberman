#include "tiledisplay.hpp"
#include "screen.hpp"
#include "entitymanager.hpp"

TileDisplay::TileDisplay(Screen* screen): m_screen(screen)
{}

TileDisplay::type_key TileDisplay::requirement() const
{
    return makeRequirement();
}

//void TileDisplay::setScreen(Screen* screen)
//{
//    m_screen = screen;
//}

void TileDisplay::do_update(Entity& entity, double)
{
    if(!m_screen) return;
    Graphic& g = EntityManager::getComponent<Graphic>(entity);
    TilePosition& pos = EntityManager::getComponent<TilePosition>(entity);
    m_screen->addTile(g.fileName(), pos.x(), pos.y());
}

void TileDisplay::preUpdate()
{
    if(!m_screen) return;
    m_screen->resetImage();
}

void TileDisplay::postUpdate()
{
    if(!m_screen) return;
}
