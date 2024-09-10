#include "Multivector.h"

namespace galg {

Multivector2::Multivector2() {}

Multivector2::Multivector2(double scalar, double x, double y, double bivector) :
    m_vector{x, y}, m_rotor{scalar, bivector} {}

Multivector2::Multivector2(Vec2 vector, Rotor2 rotor) :
    m_vector{vector}, m_rotor{rotor} {}

Multivector2::Multivector2(const Multivector2& v) :
    m_vector{v.m_vector}, m_rotor{v.m_rotor} {}

Multivector2::Multivector2(Multivector2&& v) :
    m_vector{std::move(v.m_vector)}, m_rotor{std::move(v.m_rotor)} {}

Multivector2& Multivector2::operator=(Multivector2 o)
{
    m_vector = o.vector();
    m_rotor = o.rotor();
    return *this;
}

double Multivector2::scalar() const
{
    return m_rotor.real();
}

double Multivector2::bivector() const
{
    return m_rotor.imag();
}

double Multivector2::x() const
{
    return m_vector.x();
}

double Multivector2::y() const
{
    return m_vector.y();
}

Vec2 Multivector2::vector() const
{
    return m_vector;
}

Rotor2 Multivector2::rotor() const
{
    return m_rotor;
}

std::pair<Vec2, Rotor2> Multivector2::parts() const
{
    return {m_vector, m_rotor};
}

Multivector2 Multivector2::operator-() const
{
    return {-m_vector, -m_rotor};
}

Multivector2& Multivector2::operator+=(const Multivector2& o)
{
    m_vector += o.m_vector;
    m_rotor += o.m_rotor;
    return *this;
}

Multivector2& Multivector2::operator-=(const Multivector2& o)
{
    return *this += (-o);
}

Multivector2& Multivector2::operator/=(double s)
{
    return *this *= 1 / s;
}

Multivector2& Multivector2::operator*=(const Multivector2& o)
{
    *this = {vector() * o.rotor() + rotor() * o.vector(), vector() * o.vector() + rotor() * o.rotor()};
    return *this;
}

Multivector2& Multivector2::operator*=(double s)
{
    m_vector *= s;
    m_rotor *= s;
    return *this;
}

Multivector2 operator+(const Multivector2& a, const Multivector2& b)
{
    return Multivector2{a} += b;
}

Multivector2 operator-(const Multivector2& a, const Multivector2& b)
{
    return Multivector2{a} -= b;
}

Multivector2 operator*(const Multivector2& a, double s)
{
    return Multivector2{a} *= s;
}

Multivector2 operator/(const Multivector2& a, double s)
{
    return Multivector2{a} /= s;
}

Multivector2 operator*(double s, const Multivector2& a)
{
    return Multivector2{a} *= s;
}

Multivector2 operator/(double s, const Multivector2& a)
{
    return Multivector2{a} /= s;
}

Rotor2 operator*(const Vec2& a, const Vec2& b)
{
    return {dot(a, b), a.x() * b.y() - a.y() * b.x()};
}

Vec2 operator*(const Vec2& a, const Rotor2& b)
{
    return b.real() * a + b.imag() * Vec2{-a.y(), a.x()};
}

Vec2 operator*(const Rotor2& a, const Vec2& b)
{
    return a.real() * b + a.imag() * Vec2{b.y(), -b.x()};
}

Multivector2 operator*(const Multivector2& a, const Multivector2& b)
{
    return Multivector2{a} *= b;
}

// Multivector2 Multivector2::makeRotor(double angle)
// {
//     return {{}, {std::cos(angle), std::sin(angle)}};
// }

} // namespace galg
