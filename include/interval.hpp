#pragma once

#include "rtweekend.hpp"
class interval
{
public:
    double                min, max;
    static const interval empty, universe;

    interval()
        : min(+infinity)
        , max(-infinity)
    {
    }

    interval(double min, double max)
        : min(min)
        , max(max)
    {
    }

    double size() const
    {
        return max - min;
    }

    double contains(double x) const
    {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const
    {
        return min < x && x < max;
    }
};

const interval interval::empty    = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);
