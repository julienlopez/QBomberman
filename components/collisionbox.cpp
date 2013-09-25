#include "collisionbox.hpp"

CollisionBox::CollisionBox()
{
}

CollisionBox::CollisionBox(const CollisionBox&): CRTP_Component<CollisionBox>()
{
}
