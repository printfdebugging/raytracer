#pragma once

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

double infinity = std::numeric_limits<double>::infinity();
double pi       = 3.1415926535897932385;

inline double degrees_to_radians(double degrees)
{
    return degrees * pi / 180.0;
}

#include "color.hpp"
#include "interval.hpp"
#include "ray.hpp"
#include "vec3.hpp"
