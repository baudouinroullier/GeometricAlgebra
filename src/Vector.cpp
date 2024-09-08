#include "Vector.h"


namespace galg
{
Vec2::Vec2() {}

Vec2::Vec2(double x, double y)
{
    m_values = {x, y};
}

double Vec2::x() const
{
    return m_values[0];
}

double Vec2::y() const
{
    return m_values[1];
}

double& Vec2::x()
{
    return m_values[0];
}

double& Vec2::y()
{
    return m_values[1];
}

Vec3::Vec3() {}

Vec3::Vec3(double x, double y, double z)
{
    m_values = {x, y, z};
}

double Vec3::x() const
{
    return m_values[0];
}

double Vec3::y() const
{
    return m_values[1];
}

double Vec3::z() const
{
    return m_values[2];
}

double& Vec3::x()
{
    return m_values[0];
}

double& Vec3::y()
{
    return m_values[1];
}

double& Vec3::z()
{
    return m_values[2];
}
}
