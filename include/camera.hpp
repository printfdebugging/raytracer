#pragma once

#include "hittable.hpp"

class camera
{
public:
    double aspect_ratio = 16.0 / 9.0;
    int    image_width  = 700;

private:
    int    image_height;
    point3 center;
    point3 pixel_zero_location;
    vec3   pixel_delta_u;
    vec3   pixel_delta_v;

public:
    void render(const hittable& world)
    {
        initialize();
        std::cout << "P3" << std::endl
                  << image_width << ' ' << image_height << std::endl
                  << "255" << std::endl;

        for (int y = 0; y < image_height; ++y)
        {
            std::clog << '\r' << "scanlines remaining: " << (image_height - y) << ' ' << std::flush;
            for (int x = 0; x < image_width; ++x)
            {
                point3 pixel_center  = pixel_zero_location + (x * pixel_delta_u) + (y * pixel_delta_v);
                vec3   ray_direction = pixel_center - center;
                ray    traced_ray    = ray(center, ray_direction);
                color  pixel_color   = ray_color(traced_ray, world);
                write_color(std::cout, pixel_color);
            }
        }

        std::clog << "\rdone!\n";
    }

private:
    void initialize()
    {
        image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        center = point3(0, 0, 0);

        /*
            i was wondering why these are not the part of the camera
            class, and it seems like they don't matter really. the viewport
            dimentions don't really matter (adjusted for focal length), and
            whatever data camera stores is enough to get the directions of rays
            through each of the pixels on the viewport.
        */
        double focal_length    = 1.0;
        double viewport_height = 2.0;
        double viewport_width  = viewport_height * (double(image_width) / image_height);

        vec3 viewport_u = vec3(viewport_width, 0, 0);
        vec3 viewport_v = vec3(0, -viewport_height, 0);
        pixel_delta_u   = viewport_u / image_width;
        pixel_delta_v   = viewport_v / image_height;

        point3 viewport_upper_left = center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
        pixel_zero_location        = viewport_upper_left + (pixel_delta_u + pixel_delta_v) / 2;
    }

    color ray_color(const ray& traced_ray, const hittable& world)
    {
        hit_record rec;
        if (world.hit(traced_ray, interval(0, infinity), rec))
        {
            return 0.5 * (rec.normal + color(1, 1, 1));
        }

        vec3   unit_direction    = unit_vector(traced_ray.direction());
        double value_bw_zero_one = (unit_direction.y() + 1.0) / 2;
        return (1.0 - value_bw_zero_one) * color(1.0, 1.0, 1.0) + value_bw_zero_one * color(0.5, 0.7, 1.0);
    }
};
