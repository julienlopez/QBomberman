#include "entitymanager.hpp"
#include <components/screenposition.hpp>
#include <components/graphic.hpp>

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

void EntityManager::createBomb(const ScreenPosition& position)
{
    Entity::type_list_components lst;
    Entity::up_component pos(new ScreenPosition(position));
    lst.push_back(std::move(pos));
    Graphic* graphic = new Graphic("images/bomb.png");
    lst.push_back(Entity::up_component(graphic));
    addEntity(std::move(lst));
}
