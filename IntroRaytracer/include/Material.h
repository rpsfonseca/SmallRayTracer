#pragma once

#include "maths/vec3.h"
#include "ray.h"
#include "Hit.h"

class Material
{
public:
    Material();
    ~Material();

    virtual bool scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const = 0;
};