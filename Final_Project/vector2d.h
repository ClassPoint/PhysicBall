#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

struct Vector2D
{
    double x;
    double y;

    Vector2D ();
    Vector2D (double x, double y);

    Vector2D& operator *= (double scalar);
    double getLength() const;
};

Vector2D operator + (Vector2D const& l, Vector2D const& r);
Vector2D operator - (Vector2D const& l, Vector2D const& r);
Vector2D operator * (Vector2D const& v, double scalar);
Vector2D operator * (double scalar, Vector2D const& v);

std::ostream& operator << (std::ostream& s, Vector2D const& v);
std::istream& operator >> (std::istream& s, Vector2D& v);

#endif // VECTOR2D_H
