#include "vector2d.h"
#include <cmath>
#include <cassert>

Vector2D::Vector2D() : x (0.0), y(0.0)
{

}

Vector2D::Vector2D (double x, double y) : x(x), y(y)
{
}

Vector2D& Vector2D::operator *= (double scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

double Vector2D::getLength() const
{
    return sqrt(x * x + y * y);
}

Vector2D operator + (Vector2D const& l, Vector2D const& r)
{
    return Vector2D(l.x + r.x, l.y + r.y);
}

Vector2D operator - (Vector2D const& l, Vector2D const& r)
{
    return Vector2D(l.x - r.x, l.y - r.y);
}

Vector2D operator * (Vector2D const& v, double scalar)
{
    return Vector2D(v.x * scalar, v.y * scalar);
}

Vector2D operator * (double scalar, Vector2D const& v)
{
    return Vector2D(v.x * scalar, v.y * scalar);
}

std::ostream& operator <<(std::ostream& s, Vector2D const& v)
{
    s << v.x << ',' << v.y << std::endl;
    return s;
}

std::istream& operator >>(std::istream& s, Vector2D& v)
{
    char d;
    double x;
    double y;
    s >> x >> d >> y;
    assert(',' == d);
    v.x = static_cast<int>(x);
    v.y =static_cast<int>(y);
    return s;
}
