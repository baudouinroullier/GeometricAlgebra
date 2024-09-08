#include "Multivector.h"


namespace galg
{
Multivector2::Multivector2()
{
}

double Multivector2::scalar() const
{
    return m_values[0];
}

Vec2 Multivector2::vector() const
{
    return {m_values[1], m_values[2]};
}

double Multivector2::bivector() const
{
    return m_values[3];
}
}
