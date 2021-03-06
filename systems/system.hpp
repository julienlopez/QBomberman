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

private:
    virtual void preUpdate();
    virtual void postUpdate();
    virtual void do_update(double dt) =0;
};

#endif // SYSTEM_HPP
