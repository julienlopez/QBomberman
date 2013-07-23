#ifndef CRTP_SYSTEM_HPP
#define CRTP_SYSTEM_HPP

#include "system.hpp"
#include "systemfactory.hpp"

template<class T> class CRTP_System : public System
{
protected:
    template<typename... Args> CRTP_System(Args&&... args): System(std::forward<Args>(args)...)
    {}

    virtual type_key key() const
    {
        return s_key;
    }

    virtual type_key requirement() const override
    {
        return T::makeRequirement();
    }

public:
    static const type_key s_key;
};

template<class T> const typename CRTP_System<T>::type_key CRTP_System<T>::s_key = SystemFactory::registerProduct([](){ return new T(); });

#endif // CRTP_SYSTEM_HPP
