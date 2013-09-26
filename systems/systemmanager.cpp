#include "systemmanager.hpp"
#include "screendisplay.hpp"
#include "movement.hpp"
#include "physics.hpp"
#include "lifetimemanager.hpp"
#include "bombtrigger.hpp"

SystemManager::SystemManager()
{
}

std::size_t SystemManager::count()
{
    return instance().m_container.size();
}

void SystemManager::update(double dt)
{
    for(const up_system& s : instance().m_container)
    {
        s->update(dt);
    }
    EntityManager::removeScheduledEntities();
}

void SystemManager::add(up_system&& system)
{
    instance().m_container.push_back(std::move(system));
}

void SystemManager::addScreenDisplaySystem(Screen* screen)
{
    add(up_system(new ScreenDisplay(screen)));
}

void SystemManager::addMovementSystem()
{
    add(SystemManager::up_system(SystemFactory::create(Movement::s_key)));
}

void SystemManager::addPhysicsSystem()
{
    add(SystemManager::up_system(SystemFactory::create(Physics::s_key)));
}

void SystemManager::addLifeTimeManager()
{
    add(SystemManager::up_system(SystemFactory::create(LifeTimeManager::s_key)));
}
void SystemManager::addBombTrigger()
{
    add(SystemManager::up_system(SystemFactory::create(BombTrigger::s_key)));
}
