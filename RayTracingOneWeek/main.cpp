#include "ray.h"
#include "vec3.h"
#include "rtweekend.h"

#include "color.h"
#include "hittable_list.h"
#include "sphere.h"
#include "material.h"

#include "camera.h"

#include <iostream>
#include <thread>
#include <mutex>

// Image
const double aspect_ratio = 16.0 / 9.0;
const int image_width = 1600;
const int image_height = static_cast<int>(image_width / aspect_ratio);
const int max_depth = 50;
const int samples_per_pixel = 60;

// World
hittable_list world;

// Camera
camera cam;

std::vector<std::vector<color>> color_table(image_height + 1, std::vector<color>(image_width + 1));

// ray recursion
color ray_color(const ray &r, const hittable &world, int depth) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0, 0, 0);

    // 几何体的颜色
    if (world.hit(r, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;

        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth - 1);
        return color(0, 0, 0);
    }

    // 背景色
    vec3 unit_direction = unit_vector(r.direction());
    // x y z 映射 r g b
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

void scan_calculate_color(int height, int width) {
    int i = width, j = height;
    color pixel_color(0, 0, 0);
    for (int s = 0; s < samples_per_pixel; ++s) {
        double u = (i + random_double()) / (image_width - 1.0);
        double v = (j + random_double()) / (image_height - 1.0);
        ray r = cam.get_ray(u, v);
        pixel_color += ray_color(r, world, max_depth);
    }
//    write_color(std::cout, pixel_color, samples_per_pixel);
    write_color_table(pixel_color, samples_per_pixel, color_table,j ,i);
}

int main() {
    shared_ptr<lambertian> material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
//    shared_ptr<lambertian> material_center = make_shared<lambertian>(color(0.7, 0.3, 0.3));
//    shared_ptr<metal> material_left = make_shared<metal>(color(0.8, 0.8, 0.8), 0.3);
    shared_ptr<dielectric> material_center = make_shared<dielectric>(1.5);
    shared_ptr<dielectric> material_left = make_shared<dielectric>(1.5);
    shared_ptr<metal> material_right = make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

//    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
//    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3(0.0, 0.0, -1.0), 0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\routput remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            scan_calculate_color(j, i);
        }
    }

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\routput remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            out_color_table(std::cout, color_table, j, i);
        }
    }

    std::cerr << "\nDone.\n";
}