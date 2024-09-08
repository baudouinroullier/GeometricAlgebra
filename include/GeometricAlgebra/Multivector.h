#ifndef MULTIVECTOR_H
#define MULTIVECTOR_H

#include <Vector.h>

namespace galg
{
using Scalar = double;

class Bivector // reuse std::complex i
{
public:

protected:
    double value;
};

class Multivector2
{
public:
    Multivector2() {}
    Multivector2(Scalar scalar, Vec2 vector, Bivector bivector) :
    m_values{scalar, vector.x(), vector.y(), bivector}
    {}

    double scalar() const;
    Vec2 vector() const;
    double bivector() const;

    Multivector2 operator-() const { Multivector2 ret; std::ranges::transform(m_values, ret.m_values.begin(), std::negate{}); return ret; }

    Multivector2& operator+= (const Multivector2& o) { std::ranges::transform(m_values, o.m_values, m_values.begin(), std::plus{}); return *this; }
    Multivector2& operator-= (const Multivector2& o) { return *this += (-o); }

    Multivector2& operator*= (double s) { for(double& v : m_values) v *= s; return *this; }
    Multivector2& operator/= (double s) { return *this *= 1/s; }

    Multivector2& operator*= (const Multivector2& o)
    {
        // Multivector2 tmp;
        // tmp.m_values[0] = scalar() * o.scalar() + dot(vector(), o.vector()) - bivector() * o.bivector();
        // tmp.m_values[0] = scalar() * o.vector().x() + o.scalar() * vector().x() + ;
        // tmp.m_values[0] = dot(*this, o);
        // tmp.m_values[0] = dot(*this, o);
        // return *this;
    }

    // probably not very useful functions
    template<int N_> friend double dot(const Vec<N_>& a, const Vec<N_>& b);

    double norm1() const { return std::accumulate(m_values.begin(), m_values.end(), 0., [](double acc, double i){ return acc + std::abs(i); }); }
    double norm2() const { return std::sqrt(dot(*this, *this)); }
    double normP(double p) const { return std::pow(std::accumulate(m_values.begin(), m_values.end(), 0., [p](double acc, double i){ return acc + std::pow(i, p); }), 1./p); }
    double normInf(double p) const { return std::ranges::max(m_values); }

protected:
    std::array<double, 4> m_values;
};

double dot(const Multivector2& a, const Multivector2& b) { return std::inner_product(a.m_values.begin(), a.m_values.end(), b.m_values.begin(), 0.); }

Multivector2 operator+ (const Multivector2& a, const Multivector2& b) { return Multivector2{a} += b; }
Multivector2 operator- (const Multivector2& a, const Multivector2& b) { return Multivector2{a} -= b; }

Multivector2 operator* (const Multivector2& a, double s) { return Multivector2{a} *= s; }
Multivector2 operator/ (const Multivector2& a, double s) { return Multivector2{a} /= s; }
Multivector2 operator* (double s, const Multivector2& a) { return Multivector2{a} *= s; }
Multivector2 operator/ (double s, const Multivector2& a) { return Multivector2{a} /= s; }

// scalar*scalar
Scalar operator*(Bivector a, Bivector b) { return -a*b; }
}

#endif // MULTIVECTOR_H
