#include "entitymanager.hpp"

EntityManager::type_key EntityManager::geTkey(type_id id)
{
    EntityManager& inst = instance();
//    type_map::const_iterator i = inst.m_entities.find(id);
//    if(i == inst.m_entities.end()) return 0;
//    return i->second.key;
    if(id >= inst.m_entities.size()) return 0;
    return inst.m_entities[id].key();
}

EntityManager::type_key EntityManager::addEntity(Entity::type_list_components&& lst)
{
    EntityManager& inst = instance();
    type_key res = inst.m_entities.size();
    inst.m_entities.emplace_back(std::move(lst));
    return res;
}
