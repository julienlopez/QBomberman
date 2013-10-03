#ifndef IDGENERATOR_HPP
#define IDGENERATOR_HPP

#include "noncopiable.hpp"

#include <list>

BEGIN_NAMESPACE_UTILS

template<class T> class IdGenerator : public noncopiable
{
public:
    IdGenerator(): m_last(0)
    {}

    T operator()()
    {
        if(m_freeOnes.empty())
            return ++m_last;
        T res = m_freeOnes.front();
        m_freeOnes.pop_front();
        return res;
    }

private:
    T m_last;
    std::list<T> m_freeOnes;
};

END_NAMESPACE_UTILS

#endif // IDGENERATOR_HPP
