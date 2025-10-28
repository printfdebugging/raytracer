#include "color.hpp"

/*
    raytracing could mean many things, we are writing
    a `path tracer` here, a fairly general one. another
    approach is `lumen` which is faster at runtime but
    creates worst shadows and has less details compared
    to path tracer.
*/
int main()
{
    int image_width  = 256;
    int image_height = 256;

    std::cout << "P3" << std::endl
              << image_width << ' ' << image_height << std::endl
              << "255" << std::endl;

    for (int y = 0; y < image_height; ++y)
    {
        std::clog << '\r' << "scanlines remaining: " << (image_height - y) << ' ' << std::flush;

        for (int x = 0; x < image_width; ++x)
        {
            /*
                `x / width - 1` goes from 0 to 1 across
                the width of the image, same for the
                other expression in vertical direction.
            */
            color pixel_color = color(double(x) / (image_width - 1),
                                      double(y) / (image_height - 1),
                                      0.0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rdone!\n";
    return 0;
}
