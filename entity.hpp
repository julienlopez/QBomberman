#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <components/component.hpp>

#include <list>
#include <memory>

class Entity
{
public:
    typedef Component::type_key type_key;
    typedef std::unique_ptr<Component> up_component;
    typedef std::list<up_component> type_list_components;

    Entity();
    Entity(type_list_components&& lst);

    void add(up_component&& comp);
    void remove(type_key key);

    type_key key() const;

private:
    type_key m_key;
    type_list_components m_components;

    static type_key makeKey(const type_list_components& lst);
};

#endif // ENTITY_HPP
