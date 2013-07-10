#include "entitymanager.hpp"

EntityManager::type_key EntityManager::geTkey(type_id id)
{
    EntityManager& inst = instance();
    type_map::const_iterator i = inst.m_entities.find(id);
    if(i == inst.m_entities.end()) return 0;
    return i->second.key;
}
