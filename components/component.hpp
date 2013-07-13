#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <typedefs.hpp>
#include <utils/clonable.hpp>

class Component : public utils::clonable<Component>
{
public:
    typedef QBomberMan::type_key type_key;
    static constexpr uint8_t nbMax = 16;

    virtual ~Component() = default;

    Component& operator=(const Component&) = delete;
    Component& operator=(Component&&) = delete;

    virtual type_key key() const = 0;

protected:
    Component() = default;
};

#endif // COMPONENT_HPP
