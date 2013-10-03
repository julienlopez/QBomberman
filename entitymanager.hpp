#ifndef __ENTITYMANAGER_HPP__
#define __ENTITYMANAGER_HPP__

#include <utils/singleton.hpp>
#include <utils/idgenerator.hpp>

#include "entity.hpp"

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <cassert>

class EntityManager : private utils::Singleton<EntityManager>
{
    friend class utils::Singleton<EntityManager>;

public:
    typedef std::size_t type_id;
    typedef Component::type_key type_key;
    using EntityId = QBomberMan::EntityId;
    using type_generator = utils::IdGenerator<EntityId>;
    using type_entity_key = Component::type_key;
    using up_component = std::unique_ptr<Component>;
    using type_multimap_entities_components = std::multimap<EntityId, up_component>;
    using type_map_entities_keys = std::map<EntityId, type_entity_key>;

    static type_key addEntity(Entity::type_list_components&& lst);

    static void for_each(std::function<void(EntityId, type_entity_key)> f);

    static void scheduleToRemoveEntity(EntityId entity);

    static void removeScheduledEntities();

    template<class COMPONENT> static COMPONENT& getComponent(EntityId entity)
    {
        EntityManager& inst = instance();
        auto i = inst.findComponentByKey(entity, COMPONENT::s_key);
        if(i == inst.m_entitiesComponents.end())
            throw std::logic_error("No such component " + std::string(typeid(COMPONENT).name()) + "for entity " + std::to_string(entity));
        return static_cast<COMPONENT&>(*(i->second));
    }

    template<class COMPONENT> static bool hasComponent(EntityId entity)
    {
        EntityManager& inst = instance();
        type_map_entities_keys::const_iterator i = inst.find(entity);
        if(i == inst.m_entitiesKeys.end()) {
            throw std::logic_error("No such entity " + std::to_string(entity));
        }
        return (i->second & COMPONENT::s_key) == COMPONENT::s_key;
    }

private:
    type_map_entities_keys m_entitiesKeys;
    type_multimap_entities_components m_entitiesComponents;
    std::list<EntityId> m_entitiesToRemove;
    type_generator m_idGenerator;

    EntityManager() = default;

    bool exists(EntityId entity) const;

    type_map_entities_keys::const_iterator find(EntityId entity) const;

    std::pair<type_multimap_entities_components::const_iterator, type_multimap_entities_components::const_iterator> getComponents(EntityId entity) const;

    std::pair<type_multimap_entities_components::iterator, type_multimap_entities_components::iterator> getComponents(EntityId entity);

    type_entity_key createNewEntity();

    void addComponent(EntityId entity, up_component&& component);

    type_multimap_entities_components::iterator findComponentByKey(EntityId entity, Component::type_key key);

    template<class COMPONENT> void removeComponent(EntityId entity)
    {
        type_multimap_entities_components::iterator i = findComponentByKey(entity, COMPONENT::s_key);
        if(i == m_entitiesComponents.end())
            throw std::logic_error("No such component " + std::string(typeid(COMPONENT).name()) + "for entity " + std::to_string(entity));
        assert(i != m_entitiesComponents.end());
        m_entitiesComponents.erase(i);
    }
};

#endif
