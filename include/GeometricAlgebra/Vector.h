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
template <int N>
class Vec
{
public:
    Vec<N> operator-() const { Vec<N> ret; std::ranges::transform(m_values, ret.m_values.begin(), std::negate{}); return ret; }

    Vec<N>& operator+= (const Vec<N>& o) { std::ranges::transform(m_values, o.m_values, m_values.begin(), std::plus{}); return *this; }
    Vec<N>& operator-= (const Vec<N>& o) { return *this += (-o); }

    Vec<N>& operator*= (double s) { for(double& v : m_values) v *= s; return *this; }
    Vec<N>& operator/= (double s) { return *this *= 1/s; }

    friend double dot(const Vec<N>& a, const Vec<N>& b) { return std::inner_product(a.m_values.begin(), a.m_values.end(), b.m_values.begin(), b.m_values.end()); }

    double norm1() const { return std::accumulate(m_values.begin(), m_values.end(), 0., [](double acc, double i){ return acc + std::abs(i); }); }
    double norm2() const { return std::sqrt(dot(*this, *this)); }
    double normP(double p) const { return std::pow(std::accumulate(m_values.begin(), m_values.end(), 0., [p](double acc, double i){ return acc + std::pow(i, p); }), 1./p); }
    double normInf(double p) const { return std::ranges::max(m_values); }

protected:
    std::array<double, N> m_values{};
};

template<int N> Vec<N> operator+ (const Vec<N>& a, const Vec<N>& b) { return Vec<N>{a} += b; }
template<int N> Vec<N> operator- (const Vec<N>& a, const Vec<N>& b) { return Vec<N>{a} -= b; }

template<int N> Vec<N> operator* (const Vec<N>& a, double s) { return Vec<N>{a} *= s; }
template<int N> Vec<N> operator/ (const Vec<N>& a, double s) { return Vec<N>{a} /= s; }
template<int N> Vec<N> operator* (double s, const Vec<N>& a) { return Vec<N>{a} *= s; }
template<int N> Vec<N> operator/ (double s, const Vec<N>& a) { return Vec<N>{a} /= s; }


class Vec2 : public Vec<2>
{
public:
    Vec2() {}
    Vec2(double x, double y) { m_values = {x,y}; }

    double x() const { return m_values[0]; }
    double y() const { return m_values[1]; }
    double& x() { return m_values[0]; }
    double& y() { return m_values[1]; }
};

class Vec3 : public Vec<3>
{
public:
    Vec3() {}
    Vec3(double x, double y, double z) { m_values = {x,y,z}; }

    double x() const { return m_values[0]; }
    double y() const { return m_values[1]; }
    double z() const { return m_values[2]; }
    double& x() { return m_values[0]; }
    double& y() { return m_values[1]; }
    double& z() { return m_values[2]; }
};
}

#ifdef ADD_FMT_FORMATTERS
// #include <fmt/format.h>

// namespace fmt
// {
// template<int N>
// struct formatter<galg::Vec<N>> : public fmt::formatter<double>
// {
//     template <typename FormatContext>
//     auto format(const galg::Vec<N>& vec, FormatContext& ctx) -> decltype (ctx.out())
//     {
//         ctx.advance_to(fmt::format_to(ctx.out(), "Vector of size {}", N));
//         for (int i=0; i<N; ++i)
//         {
//             ctx.advance_to(fmt::format_to(ctx.out(), "\n  | "));
//             ctx.advance_to(fmt::formatter<double>::format(vec(i), ctx));
//             ctx.advance_to(fmt::format_to(ctx.out(), " |"));
//         }
//         return ctx.out();
//     }
// };


// template<> struct formatter<galg::Vec2> : public fmt::formatter<galg::Vec<2>>
// {
//     template <typename FormatContext>
//     auto format(const galg::Vec2& vec, FormatContext& ctx) -> decltype (ctx.out())
//     {
//         return fmt::formatter<galg::Vec<2>>::format(static_cast<galg::Vec<2>>(vec), ctx);
//     }
// };
// template<> struct formatter<galg::Vec3> : public fmt::formatter<galg::Vec<3>>
// {
//     template <typename FormatContext>
//     auto format(const galg::Vec3& vec, FormatContext& ctx) -> decltype (ctx.out())
//     {
//         return fmt::formatter<galg::Vec<3>>::format(static_cast<galg::Vec<3>>(vec), ctx);
//     }
// };

// }

#endif

#endif // VECTOR_H
