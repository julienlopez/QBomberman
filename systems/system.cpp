#include "system.hpp"
#include "entitymanager.hpp"

void System::update(double dt)
{
    System& s = *this;
    EntityManager::for_each([&s, dt](Entity& e)
        {
            if((e.key() & s.requirement()) != s.requirement()) return;
            s.do_update(e, dt);
        });
}
