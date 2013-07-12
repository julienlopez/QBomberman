#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "typedefs.hpp"

class Component
{
public:
    typedef QBomberMan::type_key type_key;
    static constexpr uint8_t nbMaxComponents = 16;

    virtual ~Component() = default;

    Component& operator=(const Component&) = delete;
    Component& operator=(Component&&) = delete;

    virtual type_key key() const = 0;
    virtual Component* clone() const = 0;

protected:
    Component() = default;
    Component(const Component&) = default;
    Component(Component&&) = default;
};

#endif // COMPONENT_HPP
