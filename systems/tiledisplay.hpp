#ifndef TILEDISPLAY_HPP
#define TILEDISPLAY_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/graphic.hpp>
#include <components/tileposition.hpp>

class TileDisplay : public CRTP_System<TileDisplay>, public RequirementMaker<Graphic, TilePosition>
{
public:
    TileDisplay();

    virtual type_key requirement() const override;

private:
    virtual void do_update(Entity& entity, double dt) override;
};

#endif // TILEDISPLAY_HPP
