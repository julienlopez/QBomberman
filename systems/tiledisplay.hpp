#ifndef TILEDISPLAY_HPP
#define TILEDISPLAY_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/graphic.hpp>
#include <components/tileposition.hpp>

class Screen;

class TileDisplay : public CRTP_System<TileDisplay>, public RequirementMaker<Graphic, TilePosition>
{
public:
    TileDisplay(Screen* screen = 0);

private:
    virtual void do_update(Entity& entity, double dt) override;

    Screen* m_screen;
};

#endif // TILEDISPLAY_HPP
