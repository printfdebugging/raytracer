#pragma once

#include "rtweekend.hpp"

class hit_record
{
public:
    point3 surface_point;
    vec3   normal;
    double ray_magnitude;
    bool   front_face;

    /*
        sets the hit record normal vector. the parameter
        `outward_normal` is assumed to have unit length.
    */
    void set_face_normal(const ray& r, const vec3& outward_normal)
    {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal     = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
public:
    virtual ~hittable()                                                   = default;
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};
