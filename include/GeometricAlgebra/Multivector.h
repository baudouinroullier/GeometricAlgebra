#ifndef MULTIVECTOR_H
#define MULTIVECTOR_H

#include "Vector.h"
#include <complex>
#include <tuple>

namespace galg
{
using Rotor2 = std::complex<double>;

class Multivector2
{
public:
    Multivector2();
    Multivector2(double scalar, double x, double y, double bivector);
    Multivector2(Vec2 vector, Rotor2 rotor);
    Multivector2(const Multivector2& v);
    Multivector2(Multivector2&& v);

    Multivector2& operator=(Multivector2 o);

    // Multivector2 makeRotor(double angle);

    double scalar() const;
    double bivector() const;
    double x() const;
    double y() const;

    Vec2 vector() const;
    Rotor2 rotor() const;
    std::pair<Vec2, Rotor2> parts() const;

    Multivector2 operator-() const;

    Multivector2& operator+=(const Multivector2& o);
    Multivector2& operator-=(const Multivector2& o);

    Multivector2& operator*=(double s);
    Multivector2& operator/=(double s);

    Multivector2& operator*=(const Multivector2& o);

    Multivector2 conj() const;
    Multivector2 inverse() const;

protected:
    Vec2 m_vector;
    Rotor2 m_rotor;
};

Multivector2 operator+(const Multivector2& a, const Multivector2& b);
Multivector2 operator-(const Multivector2& a, const Multivector2& b);

Multivector2 operator*(const Multivector2& a, double s);
Multivector2 operator/(const Multivector2& a, double s);
Multivector2 operator*(double s, const Multivector2& a);
Multivector2 operator/(double s, const Multivector2& a);

Rotor2 operator*(const Vec2& a, const Vec2& b);
Vec2 operator*(const Vec2& a, const Rotor2& b);
Vec2 operator*(const Rotor2& a, const Vec2& b);
Multivector2 operator*(const Multivector2& a, const Multivector2& b);
}


class Transform2D
{

};


#ifdef ADD_FMT_FORMATTERS
#include <fmt/format.h>

namespace fmt
{
template<>
struct formatter<galg::Rotor2> : public fmt::formatter<double>
{
    template <typename FormatContext>
    auto format(const galg::Rotor2& rotor, FormatContext& ctx) const -> decltype (ctx.out())
    {
        ctx.advance_to(fmt::format_to(ctx.out(), "("));
        ctx.advance_to(fmt::formatter<double>::format(rotor.real(), ctx));
        ctx.advance_to(fmt::format_to(ctx.out(), ", "));
        ctx.advance_to(fmt::formatter<double>::format(rotor.imag(), ctx));
        ctx.advance_to(fmt::format_to(ctx.out(), "i)"));
        return ctx.out();
    }
};

template<>
struct formatter<galg::Multivector2> : public fmt::formatter<double>
{
    template <typename FormatContext>
    auto format(const galg::Multivector2& multivec, FormatContext& ctx) const -> decltype (ctx.out())
    {
        ctx.advance_to(fmt::format_to(ctx.out(), "("));
        ctx.advance_to(fmt::formatter<galg::Vec2>{}.format(multivec.vector(), ctx));
        ctx.advance_to(fmt::format_to(ctx.out(), ", "));
        ctx.advance_to(fmt::formatter<galg::Rotor2>{}.format(multivec.rotor(), ctx));
        ctx.advance_to(fmt::format_to(ctx.out(), ")"));
        return ctx.out();
    }
};
}

#endif

#endif // MULTIVECTOR_H
