#ifndef CRTP_COMPONENT_HPP
#define CRTP_COMPONENT_HPP

#include "component.hpp"
#include "componentfactory.hpp"

template<class T> class CRTP_Component : public Component
{
protected:
    template<typename... Args> CRTP_Component(Args&&... args): Component(std::forward<Args>(args)...)
    {}

    virtual type_key key() const override final
    {
        return s_key;
    }

    virtual Component* clone() const override final
    {
        return new T(static_cast<const T&>(*this));
    }

public:
    static const type_key s_key;
};

template<class T> const typename CRTP_Component<T>::type_key CRTP_Component<T>::s_key = ComponentFactory::registerProduct([](){ return new T(); });

#endif // CRTP_COMPONENT_HPP
