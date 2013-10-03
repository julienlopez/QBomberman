#ifndef DROPBOMBINPUTHANDLER_HPP
#define DROPBOMBINPUTHANDLER_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/player.hpp>
#include <components/screenposition.hpp>

class DropBombInputHandler : public CRTP_System<DropBombInputHandler>, public RequirementMaker<Player, ScreenPosition>
{
public:
    DropBombInputHandler();

    void setCurrentKey(QBomberMan::KEYS currentKey);

private:
    bool m_haveToDropBomb;

    virtual void do_update(EntityManager::EntityId entity, double dt) override;
};

#endif // DROPBOMBINPUTHANDLER_HPP
