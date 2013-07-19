#include "graphic.hpp"

Graphic::Graphic(const std::string &fileName): m_file(fileName)
{}

Graphic::Graphic(const Graphic&): CRTP_Component<Graphic>()
{}

const std::string& Graphic::fileName() const
{
    return m_file;
}
