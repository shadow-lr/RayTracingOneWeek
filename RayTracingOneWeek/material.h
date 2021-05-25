#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.h"
#include "hittable.h"

struct hit_record;

// 告诉射线如何与表面相互作用
class material {
public:
    /**
     * @brief 函数简要说明-测试函数
     * @param r_in              参数1 射线
     * @param rec               参数2 离光线起点的距离t、撞点的坐标向量p、撞点出的法向量normal.
     * @param attenuation       参数3 衰弱后的颜色值
     * @param scattered         参数4 散射射线
     *
     * @return 返回说明
     */
    virtual bool scatter(
            const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered
    ) const = 0;
};

// 兰伯特模型类
class lambertian : public material {
public:
    lambertian(const color &a) : albedo(a) {}

    virtual bool scatter(
            const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered
    ) const override {
        // 散射的向量
        vec3 scatter_direction = rec.normal + random_unit_vector();
//        vec3 scatter_direction = rec.normal + random_in_unit_sphere();
//        vec3 scatter_direction = rec.normal + random_in_hemisphere(rec.normal);

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

public:
    color albedo;
};

// 金属类
class metal : public material {
public:
    metal(const color &a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
//        scattered = ray(rec.p, reflected);
        scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

public:
    color albedo;
    double fuzz;
};

// dielectric电介质类
class dielectric : public material {
public:
    dielectric(double index_of_refraction) : ir(index_of_refraction) {}

    virtual bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override {
        attenuation = color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;

        vec3 unit_direction = unit_vector(r_in.direction());
        vec3 refracted = refract(unit_direction, rec.normal, refraction_ratio);

        scattered = ray(rec.p, refracted);
        return true;
    }
public:
    // 折射率
    double ir;  // Index Of Refraction
};

#endif