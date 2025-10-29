#pragma once

#include "rtweekend.hpp"
#include "hittable.hpp"

class sphere : public hittable
{
public:
    sphere(const point3& center, double radius)
        : center(center)
        , radius(std::fmax(0, radius))
    {
    }

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override
    {
        vec3   oc = center - r.origin();
        double a  = r.direction().length_squared();
        double h  = dot(r.direction(), oc);
        double c  = oc.length_squared() - radius * radius;

        double discriminant = (h * h) - (a * c);
        if (discriminant < 0)
            return false;

        double sqrtd = std::sqrt(discriminant);
        double root  = (h - sqrtd) / a;
        if (!ray_t.surrounds(root))
        {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.ray_magnitude   = root;
        rec.surface_point   = r.at(rec.ray_magnitude);
        vec3 outward_normal = (rec.surface_point - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }

private:
    point3 center;
    double radius;
};
