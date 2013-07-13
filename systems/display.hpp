#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/graphic.hpp>
#include <components/tileposition.hpp>

class Display : public CRTP_System<Display>, public RequirementMaker<Graphic, TilePosition>
{
public:
    Display();

    virtual type_key requirement() const override;

private:
    virtual void do_update(Entity& entity, double dt) override;
};

#endif // DISPLAY_HPP
