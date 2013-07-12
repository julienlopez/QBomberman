#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "crtp_component.hpp"

class Graphic : public CRTP_Component<Graphic>
{
public:
    Graphic();
};

#endif // GRAPHIC_HPP
