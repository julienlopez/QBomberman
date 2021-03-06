#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include <utils/singleton.hpp>

#include "system.hpp"

#include <list>
#include <memory>

class Screen;

class SystemManager : private utils::Singleton<SystemManager>
{
    friend class utils::Singleton<SystemManager>;

public:
    typedef std::unique_ptr<System> up_system;
    typedef std::list<up_system> type_list_systems;

    static std::size_t count();

    static void update(double dt);

    static void add(up_system&& system);

    static void addScreenDisplaySystem(Screen* screen);

    static void addMovementSystem();
    static void addPhysicsSystem();
    static void addLifeTimeManager();
    static void addBombTrigger();

private:
    SystemManager();

    type_list_systems m_container;

};

#endif // SYSTEMMANAGER_HPP
