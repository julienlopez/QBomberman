#include "entity.hpp"

Entity::Entity(): m_key(0)
{}

Entity::Entity(type_list_components&& lst): m_components(std::move(lst))
{
    m_key = makeKey(m_components);
}

void Entity::add(up_component&& comp)
{
    m_key |= comp->key();
    m_components.push_back(std::move(comp));
}

void Entity::remove(type_key key)
{
    m_key &= !key;
    m_components.remove_if([key](const up_component& c){ return c->key() == key; });
}

Entity::type_key Entity::key() const
{
    return m_key;
}

Entity::type_key Entity::makeKey(const type_list_components& lst)
{
    type_key res = 0;
    for(const up_component& p : lst)
    {
        res |= p->key();
    }
    return res;
}
