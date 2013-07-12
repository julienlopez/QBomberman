#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

template<typename T> class Point2D
{
public:

    static constexpr double PI = 3.14159265;

    Point2D(T x = 0, T y = 0) noexcept: m_x(x), m_y(y)
    {}

    T x() const noexcept
    {
        return m_x;
    }
    T y() const noexcept
    {
        return m_y;
    }
    void setX(T x) noexcept
    {
        m_x = x;
    }
    void setY(T y) noexcept
    {
        m_y = y;
    }

    Point2D operator+(const Point2D& p) const noexcept
    {
        return Point2D(m_x + p.m_x, m_y + p.m_y);
    }
    Point2D operator-() const noexcept
    {
        return Point2D(-m_x, -m_y);
    }
    Point2D operator-(const Point2D& p) const noexcept
    {
        return Point2D(m_x - p.m_x, m_y - p.m_y);
    }
    Point2D operator*(T d) const noexcept
    {
        return Point2D(d*m_x, d*m_y);
    }
    friend Point2D operator*(T d, const Point2D& p) noexcept
    {
        return p*d;
    }
    Point2D operator/(T d) const
    {
        return Point2D(m_x/d, m_y/d);
    }

    Point2D& operator +=(const Point2D& p)
    {
        m_x += p.m_x;
        m_y += p.m_y;
        return *this;
    }

    Point2D& operator *=(T d)
    {
        m_x *= d;
        m_y *= d;
        return *this;
    }

    Point2D& operator /=(T d)
    {
        m_x /= d;
        m_y /= d;
        return *this;
    }

    T dot(const Point2D& p) const noexcept
    {
        return m_x * p.m_x + m_y * p.m_y;
    }
    T dot() const noexcept
    {
        return dot(*this);
    }
    double length() const
    {
        return sqrt(dot());
    }

    bool operator==(const Point2D& p) const noexcept
    {
        return m_x == p.m_x && m_y == p.m_y;
    }

    bool operator!=(const Point2D& p) const noexcept
    {
        return !operator==(p);
    }

    double angle() const noexcept
    {
        double a = atan2(y(),x());
        if (a<0) a = 2*PI+a;
        return a;
    }
    void rotate(double a)
    {
        double d = length();
        double p = a + angle();
        m_x = d*cos(p);
        m_y = d*sin(p);
    }
    void rotate(const Point2D &centre, double angle)
    {
        Point2D v = (*this)-centre;
        v.rotate(angle);
        *this = centre + v;
    }

private:
    T m_x;
    T m_y;
};

typedef Point2D<int> Point;
typedef Point2D<double> PointF;

#endif // POINT_HPP
