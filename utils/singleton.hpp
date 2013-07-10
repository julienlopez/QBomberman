#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include "utils.hpp"

BEGIN_NAMESPACE_UTILS

template<class T> class Singleton {
public:
    static T& instance() {
        static T i;
        return i;
    }

private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

protected:
    Singleton() {}
};

END_NAMESPACE_UTILS

#endif // SINGLETON_HPP
