#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <numeric>
#include <ranges>

namespace galg
{
class Vec2
{
public:
    Vec2();
    Vec2(double x, double y);
    Vec2(const Vec2& v);
    Vec2(Vec2&& v);

    Vec2& operator=(Vec2 o);

    Vec2 operator-() const;

    Vec2& operator+=(const Vec2& o);
    Vec2& operator-=(const Vec2& o);

    Vec2& operator*=(double s);
    Vec2& operator/= (double s) { return *this *= 1/s; }

    friend double dot(const Vec2& a, const Vec2& b);

    double norm1() const;
    double norm2() const;
    double normP(double p) const;
    double normInf() const;

    double x() const { return m_values[0]; }
    double y() const { return m_values[1]; }
    double& x() { return m_values[0]; }
    double& y() { return m_values[1]; }

protected:
    std::array<double, 2> m_values;
};

inline double dot(const Vec2& a, const Vec2& b)
{
    return std::inner_product(a.m_values.begin(), a.m_values.end(), b.m_values.begin(), 0.);
}

Vec2 operator+(const Vec2& a, const Vec2& b);
Vec2 operator-(const Vec2& a, const Vec2& b);
Vec2 operator*(const Vec2& a, double s);
Vec2 operator/(const Vec2& a, double s);
Vec2 operator*(double s, const Vec2& a);
Vec2 operator/(double s, const Vec2& a);
}

#ifdef ADD_FMT_FORMATTERS
#include <fmt/format.h>

namespace fmt
{
template<>
struct formatter<galg::Vec2> : public fmt::formatter<double>
{
    template <typename FormatContext>
    auto format(const galg::Vec2& vec, FormatContext& ctx) const -> decltype (ctx.out())
    {
        ctx.advance_to(fmt::format_to(ctx.out(), "("));
        ctx.advance_to(fmt::formatter<double>::format(vec.x(), ctx));
        ctx.advance_to(fmt::format_to(ctx.out(), ", "));
        ctx.advance_to(fmt::formatter<double>::format(vec.y(), ctx));
        ctx.advance_to(fmt::format_to(ctx.out(), ")"));
        return ctx.out();
    }
};
}

#endif

#endif // VECTOR_H
