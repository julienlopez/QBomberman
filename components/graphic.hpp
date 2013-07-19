#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include "crtp_component.hpp"

#include <string>

class Graphic : public CRTP_Component<Graphic>
{
public:
    Graphic(const std::string& fileName = std::string());
    Graphic(const Graphic&);

    const std::string& fileName() const;

private:
    std::string m_file;
};

#endif // GRAPHIC_HPP
