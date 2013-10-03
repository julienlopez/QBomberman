#include "screendisplay.hpp"
#include "screen.hpp"
#include "entitymanager.hpp"

ScreenDisplay::ScreenDisplay(Screen* screen): m_screen(screen)
{}

void ScreenDisplay::do_update(EntityManager::EntityId entity, double)
{
    if(!m_screen) return;
    Graphic& g = EntityManager::getComponent<Graphic>(entity);
    ScreenPosition& pos = EntityManager::getComponent<ScreenPosition>(entity);
    m_screen->addObject(g.fileName(), pos.pos().x(), pos.pos().y());
}
