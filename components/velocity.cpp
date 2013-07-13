#include "velocity.hpp"

Velocity::Velocity()
{}

Velocity::Velocity(const Velocity&): CRTP_Component<Velocity>()
{}
