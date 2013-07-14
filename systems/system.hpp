#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <typedefs.hpp>

#include <utils/noncopiable.hpp>

class Entity;

class System : public utils::noncopiable
{
public:
    typedef QBomberMan::type_key type_key;

    static constexpr uint16_t nbMax = -1;

    virtual ~System() = default;

    virtual type_key requirement() const =0;

    void update(double dt);

protected:
    virtual void preUpdate();
    virtual void postUpdate();

private:
    virtual void do_update(Entity& entity, double dt) =0;
};

#endif // SYSTEM_HPP
