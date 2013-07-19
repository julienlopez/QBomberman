#ifndef __ENTITYMANAGER_HPP__
#define __ENTITYMANAGER_HPP__

#include <utils/singleton.hpp>

#include "entity.hpp"

#include <vector>
#include <stdexcept>

class EntityManager : private utils::Singleton<EntityManager>
{
    friend class utils::Singleton<EntityManager>;

public:
    typedef std::size_t type_id;
    typedef Component::type_key type_key;

	static type_key geTkey(type_id id);

    static type_key addEntity(Entity::type_list_components&& lst);

    static void for_each(std::function<void(Entity&)> f);

    template<class COMPONENT> static COMPONENT& getComponent(Entity& entity)
    {
        for(Entity::up_component& comp : entity.m_components)
        {
            if(comp->key() == COMPONENT::s_key)
                return static_cast<COMPONENT&>(*comp);
        }
        throw std::logic_error("No such component " + std::string(typeid(COMPONENT).name()) + "for that entity");
    }

private:
    EntityManager() = default;

    typedef std::vector<Entity> type_containr;

    type_containr m_entities;
};

#endif
