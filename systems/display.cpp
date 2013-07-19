#include "display.hpp"

#include <components/graphic.hpp>
#include <components/tileposition.hpp>

Display::Display()
{
}

Display::type_key Display::requirement() const
{
    return makeRequirement();
}

Display::type_key Display::makeRequirement()
{
    return Graphic::s_key | TilePosition::s_key;
}

void Display::do_update(Entity& entity, double dt)
{

}
