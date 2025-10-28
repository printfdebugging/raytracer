#pragma once

#include "vec3.hpp"

class ray
{
private:
    point3 _origin;
    vec3   _direction;

public:
    ray()
        : _origin(0, 0, 0)
        , _direction(0, 0, 0)
    {
    }

    ray(const point3& origin, const vec3& direction)
        : _origin(origin)
        , _direction(direction)
    {
    }

    const point3& origin() const
    {
        return _origin;
    }

    const vec3& direction() const
    {
        return _direction;
    }

    point3 at(double t) const
    {
        return _origin + _direction * t;
    }
};
