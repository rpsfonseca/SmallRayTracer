#pragma once

#include "Material.h"

class Metal : public Material
{
public:
    Vector3 albedo;
	float fuzziness;

public:
    Metal(const Vector3& a, float f);
    ~Metal();

    virtual bool scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const override;
};

