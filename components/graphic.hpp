#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "crtp_component.hpp"

#include <string>

class Graphic : public CRTP_Component<Graphic>
{
public:
    Graphic();
    Graphic(const Graphic&);

private:
    std::string m_file;
};

#endif // GRAPHIC_HPP
