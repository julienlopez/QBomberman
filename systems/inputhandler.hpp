#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/velocity.hpp>
#include <components/inputtovelocity.hpp>

class InputHandler : public CRTP_System<InputHandler>, public RequirementMaker<Velocity, InputToVelocity>
{
public:
    InputHandler();

    void setCurrentKey(QBomberMan::KEYS currentKey);

private:
    QBomberMan::KEYS m_currentKey;

    virtual void do_update(Entity& entity, double dt) override;
};

#endif // INPUTHANDLER_HPP
