#pragma once

#include "vec3.hpp"

typedef vec3 color;

inline void write_color(std::ostream& out, const color& pixel)
{
    double red   = pixel.x();
    double green = pixel.y();
    double blue  = pixel.z();

    /*
        we multiply with `255.999` instead of 255
        to avoid rounding errors. we want to scale
        up the colors without any loss of data in
        the scaling process.
    */
    int image_red   = int(255.999 * red);
    int image_green = int(255.999 * green);
    int image_blue  = int(255.999 * blue);

    std::cout << image_red << ' '
              << image_green << ' '
              << image_blue << std::endl;
}
