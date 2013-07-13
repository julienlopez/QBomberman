#ifndef CLONABLE_HPP
#define CLONABLE_HPP

#include <utils/noncopiable.hpp>

BEGIN_NAMESPACE_UTILS

template<class T> class clonable : public noncopiable
{
public:
    virtual T* clone() const = 0;
};

END_NAMESPACE_UTILS

#endif // CLONABLE_HPP
