#include "systemmanager.hpp"

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
}

void SystemManager::add(up_system&& system)
{
    instance().m_container.push_back(std::move(system));
}
