#ifndef SAFEPOINTER_HPP
#define SAFEPOINTER_HPP

#include <utils/utils.hpp>

BEGIN_NAMESPACE_UTILS

template<class T> class safe_pointer
{
public:
    safe_pointer(): m_pointer(nullptr)
    {}

    safe_pointer(T* p): m_pointer(p)
    {}

    safe_pointer(const safe_pointer& sp) = default;
    safe_pointer(safe_pointer&& sp) = default;

    ~safe_pointer() noexcept = default;

    safe_pointer& operator=(const safe_pointer& sp) = default;
    safe_pointer& operator=(safe_pointer&& sp) = default;

    T& operator*() const
    {
        return *m_pointer;
    }

    T* operator->() const
    {
        return m_pointer;
    }

private:
    T* m_pointer;
};

END_NAMESPACE_UTILS

#endif // SAFEPOINTER_HPP
