#include "Vector.h"

namespace galg {
Vec2::Vec2() :
    m_values{} {}

Vec2::Vec2(double x, double y) :
    m_values{x, y} {}

Vec2::Vec2(const Vec2& v) :
    m_values{v.m_values} {}

Vec2::Vec2(Vec2&& v) :
    m_values{std::move(v.m_values)} {}

Vec2& galg::Vec2::operator=(Vec2 o)
{
    m_values = o.m_values;
    return *this;
}

Vec2 Vec2::operator-() const
{
    Vec2 ret;
    std::ranges::transform(m_values, ret.m_values.begin(), std::negate{});
    return ret;
}

Vec2& Vec2::operator+=(const Vec2& o)
{
    std::ranges::transform(m_values, o.m_values, m_values.begin(), std::plus{});
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& o)
{
    return *this += (-o);
}

Vec2& Vec2::operator*=(double s)
{
    for (double& v : m_values)
        v *= s;
    return *this;
}

double Vec2::norm1() const
{
    return std::accumulate(m_values.begin(), m_values.end(), 0., [](double acc, double i) { return acc + std::abs(i); });
}

double Vec2::norm2() const
{
    return std::sqrt(dot(*this, *this));
}

double Vec2::normP(double p) const
{
    return std::pow(std::accumulate(m_values.begin(), m_values.end(), 0., [p](double acc, double i) { return acc + std::pow(i, p); }), 1. / p);
}

double Vec2::normInf() const
{
    return std::abs(std::ranges::max(m_values));
}

Vec2 operator+(const Vec2& a, const Vec2& b)
{
    return Vec2{a} += b;
}

Vec2 operator-(const Vec2& a, const Vec2& b)
{
    return Vec2{a} -= b;
}

Vec2 operator*(const Vec2& a, double s)
{
    return Vec2{a} *= s;
}

Vec2 operator/(const Vec2& a, double s)
{
    return Vec2{a} /= s;
}

Vec2 operator*(double s, const Vec2& a)
{
    return Vec2{a} *= s;
}

Vec2 operator/(double s, const Vec2& a)
{
    return Vec2{a} /= s;
}

} // namespace galg
