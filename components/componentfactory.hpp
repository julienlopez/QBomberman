#ifndef COMPONENTFACTORY_HPP
#define COMPONENTFACTORY_HPP

#include <utils/singleton.hpp>

#include "component.hpp"

#include <vector>
#include <functional>

class ComponentFactory : protected utils::Singleton<ComponentFactory>
{
    typedef std::function<Component*()> type_callback;
    typedef std::vector<type_callback> type_containr;

public:
    typedef Component::type_key type_key;

    static Component* create(type_key id);

    static type_key registerProduct(type_callback creator);

private:
    type_containr m_containr;
};

#endif // COMPONENTFACTORY_HPP
