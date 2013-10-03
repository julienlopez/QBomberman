#ifndef SCREENDISPLAY_HPP
#define SCREENDISPLAY_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/graphic.hpp>
#include <components/screenposition.hpp>

class Screen;

class ScreenDisplay : public CRTP_System<ScreenDisplay>, public RequirementMaker<Graphic, ScreenPosition>
{
public:
    ScreenDisplay(Screen* screen = 0);

private:
    virtual void do_update(EntityManager::EntityId entity, double dt) override;

    Screen* m_screen;
};

#endif // SCREENDISPLAY_HPP
