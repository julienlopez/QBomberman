#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "crtp_component.hpp"

class Player : public CRTP_Component<Player>
{
public:
    Player();
    Player(const Player& p);
};

#endif // PLAYER_HPP
