#include "system.hpp"

void System::update(double dt)
{
    preUpdate();
    do_update(dt);
    postUpdate();
}

void System::preUpdate()
{}

void System::postUpdate()
{}
