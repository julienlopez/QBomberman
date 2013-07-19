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

    virtual type_key requirement() const override;

//    void setScreen(Screen* screen);

private:
    virtual void do_update(Entity& entity, double dt) override;

    virtual void preUpdate() override;
    virtual void postUpdate() override;

    Screen* m_screen;
};

#endif // TILEDISPLAY_HPP
