#ifndef COLLISIONBOX_HPP
#define COLLISIONBOX_HPP

#include "crtp_component.hpp"

class CollisionBox : public CRTP_Component<CollisionBox>
{
public:
    CollisionBox();
    CollisionBox(const CollisionBox& cb);
};

#endif // COLLISIONBOX_HPP
