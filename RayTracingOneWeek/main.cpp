#include "ray.h"
#include "vec3.h"
#include "rtweekend.h"

#include "color.h"
#include "hittable_list.h"
#include "sphere.h"

#include "camera.h"

#include <iostream>

// ray recursion
color ray_color(const ray &r, const hittable &world, int depth) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0, 0, 0);

    // 几何体的颜色
    if (world.hit(r, 0.001, infinity, rec)) {

//        point3 target = rec.p + rec.normal + random_in_unit_sphere();
        // 更改后阴影不那么明显
        // 沿表面法线在单位球偏移中生成随机点
//        point3 target = rec.p + rec.normal + random_unit_vector();

        // 半球散射的效果
        point3 target = rec.p + random_in_hemisphere(rec.normal);
        return 0.5 * ray_color(ray(rec.p, target - rec.p), world, depth - 1);
    }

    // 背景色
    vec3 unit_direction = unit_vector(r.direction());
    // x y z 映射 r g b
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 1600;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int max_depth = 50;
    const int samples_per_pixel = 100;

    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // Camera
    camera cam;


    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / (image_width - 1.0);
                double v = (j + random_double()) / (image_height - 1.0);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world, max_depth);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}