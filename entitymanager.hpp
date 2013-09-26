#ifndef __ENTITYMANAGER_HPP__
#define __ENTITYMANAGER_HPP__

#include <utils/singleton.hpp>

#include "entity.hpp"

#include <vector>
#include <stdexcept>
#include <algorithm>

class ScreenPosition;

class EntityManager : private utils::Singleton<EntityManager>
{
    friend class utils::Singleton<EntityManager>;

public:
    typedef std::size_t type_id;
    typedef Component::type_key type_key;

	static type_key geTkey(type_id id);

    static type_key addEntity(Entity::type_list_components&& lst);

    static void for_each(std::function<void(Entity&)> f);

    static void createBomb(const ScreenPosition& position, double lifeTime);

    static void scheduleToRemoveEntity(Entity& entity);

    static void removeScheduledEntities();

    template<class COMPONENT> static COMPONENT& getComponent(Entity& entity)
    {
        Entity::type_list_components::iterator i = std::find_if(entity.m_components.begin(), entity.m_components.end(), [](Entity::up_component& comp){ return comp->key() == COMPONENT::s_key; });
        if(i == entity.m_components.end())
            throw std::logic_error("No such component " + std::string(typeid(COMPONENT).name()) + "for that entity");
        return static_cast<COMPONENT&>(**i);
    }

    template<class COMPONENT> static bool hasComponent(Entity& entity)
    {
        return std::find_if(entity.m_components.cbegin(), entity.m_components.cend(), [](const Entity::up_component& comp){ return comp->key() == COMPONENT::s_key; }) != entity.m_components.cend();
    }

private:
    EntityManager() = default;

    using type_containr = std::vector<Entity>;
    type_containr m_entities;
    std::list<type_containr::iterator> m_entitiesToRemove;
};

#endif
