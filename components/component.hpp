#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <utils/noncopiable.hpp>

class Component : public utils::noncopiable
{
public:
//    Component(const Component&) = delete;
//    Component(Component&&) = delete;

    virtual ~Component() = default;

//    Component& operator=(const Component&) = delete;
//    Component& operator=(Component&&) = delete;

protected:
    Component() = default;
};

#endif // COMPONENT_HPP
