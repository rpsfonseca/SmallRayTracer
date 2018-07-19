#pragma once
#include "Material.h"

class Lambert : public Material
{
public:
    Vector3 albedo;

public:
    Lambert(const Vector3& a);
    ~Lambert();

    virtual bool scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const override;
};
