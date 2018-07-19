#pragma once

#include "Material.h"

class Metal : public Material
{
public:
    Vector3 albedo;

public:
    Metal(const Vector3& a);
    ~Metal();

    virtual bool scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const override;
};

