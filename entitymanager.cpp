#include "entitymanager.hpp"

//#include <QDebug>
EntityManager::type_key EntityManager::addEntity(Entity::type_list_components&& lst)
{
    EntityManager& inst = instance();
    type_key res = inst.createNewEntity();
//    for(up_component&& c : lst)
    for(Entity::type_list_components::iterator i = lst.begin(); i != lst.end(); ++i)
    {
//        inst.addComponent(res, std::move(c));
        inst.addComponent(res, std::move(*i));
    }
    return res;
}

void EntityManager::for_each(std::function<void(EntityId, type_entity_key)> f)
{
    EntityManager& inst = instance();
    for(auto& p : inst.m_entitiesKeys)
    {
        f(p.first, p.second);
    }
}

void EntityManager::scheduleToRemoveEntity(EntityId entity)
{
    EntityManager& inst = instance();
    assert(inst.exists(entity));
    inst.m_entitiesToRemove.push_back(entity);
}

void EntityManager::removeScheduledEntities()
{
    EntityManager& inst = instance();
    for(auto i : inst.m_entitiesToRemove)
    {
        inst.m_entitiesComponents.erase(i);
        inst.m_entitiesKeys.erase(i);
    }
    inst.m_entitiesToRemove.clear();
}

bool EntityManager::exists(EntityId entity) const
{
    return find(entity) != m_entitiesKeys.end();
}

EntityManager::type_map_entities_keys::const_iterator EntityManager::find(EntityId entity) const
{
    return m_entitiesKeys.find(entity);
}

std::pair<EntityManager::type_multimap_entities_components::const_iterator, EntityManager::type_multimap_entities_components::const_iterator>
EntityManager::getComponents(EntityId entity) const
{
    return m_entitiesComponents.equal_range(entity);
}

std::pair<EntityManager::type_multimap_entities_components::iterator, EntityManager::type_multimap_entities_components::iterator>
EntityManager::getComponents(EntityId entity)
{
    return m_entitiesComponents.equal_range(entity);
}

EntityManager::type_entity_key EntityManager::createNewEntity()
{
    type_entity_key res = m_idGenerator();
    assert(!exists(res));
    auto p = m_entitiesKeys.insert(std::make_pair(res, 0));
    assert(p.second);
    return res;
}

void EntityManager::addComponent(EntityId entity, up_component&& component)
{
    m_entitiesKeys[entity] |= component->key();
    m_entitiesComponents.insert(std::make_pair(entity, std::move(component)));
}

EntityManager::type_multimap_entities_components::iterator EntityManager::findComponentByKey(EntityId entity, Component::type_key key)
{
    auto p = getComponents(entity);
    return std::find_if(p.first, p.second, [&key](const type_multimap_entities_components::value_type& pair){ return pair.second->key() == key; });
}
