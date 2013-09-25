#ifndef MOVEMENTINPUTHANDLER_HPP
#define MOVEMENTINPUTHANDLER_HPP

#include "crtp_system.hpp"
#include "requirementmaker.hpp"
#include <components/velocity.hpp>
#include <components/player.hpp>

#include <map>

class MovementInputHandler : public CRTP_System<MovementInputHandler>, public RequirementMaker<Velocity, Player>
{
public:
    MovementInputHandler();

    void setCurrentKey(QBomberMan::KEYS currentKey);

private:
    using type_map = std::map<QBomberMan::KEYS, PointF>;

    QBomberMan::KEYS m_currentKey;
    type_map m_map;

    virtual void do_update(Entity& entity, double dt) override;

    PointF key2Velocity(QBomberMan::KEYS key) const;
};

#endif // MOVEMENTINPUTHANDLER_HPP
