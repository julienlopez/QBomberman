#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "crtp_system.hpp"

class Display : public CRTP_System<Display>
{
public:
    Display();

    virtual type_key requirement() const override;

    static type_key makeRequirement();

private:
    virtual void do_update(Entity& entity, double dt) override;
};

#endif // DISPLAY_HPP
