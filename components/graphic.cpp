#include "graphic.hpp"

Graphic::Graphic()
{}

Graphic::Graphic(const Graphic&): CRTP_Component<Graphic>()
{}
