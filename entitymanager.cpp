#include "entitymanager.hpp"
#include <components/screenposition.hpp>
#include <components/graphic.hpp>
#include <components/lifetime.hpp>

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

void EntityManager::for_each(std::function<void(Entity&)> f)
{
    EntityManager& inst = instance();
    for(Entity& e : inst.m_entities)
    {
        f(e);
    }
}

void EntityManager::createBomb(const ScreenPosition& position, double lifeTime)
{
    Entity::type_list_components lst;
    Entity::up_component pos(position.clone());
    lst.push_back(std::move(pos));
    Entity::up_component graphic(new Graphic("images/bomb.png"));
    lst.push_back(std::move(graphic));
    Entity::up_component lt(new LifeTime(lifeTime));
    lst.push_back(std::move(lt));
    addEntity(std::move(lst));
}

void EntityManager::scheduleToRemoveEntity(Entity& entity)
{
    EntityManager& inst = instance();
    type_containr::iterator i = std::find(inst.m_entities.begin(), inst.m_entities.end(), entity);
    assert(i != inst.m_entities.end());
    inst.m_entitiesToRemove.push_back(i);
}

void EntityManager::removeScheduledEntities()
{
    EntityManager& inst = instance();
    for(auto i : inst.m_entitiesToRemove)
    {
        i->clear();
    }
    inst.m_entities.erase(std::remove_if(inst.m_entities.begin(), inst.m_entities.end(), std::bind(&Entity::empty, std::placeholders::_1)), inst.m_entities.end());
    inst.m_entitiesToRemove.clear();
}
