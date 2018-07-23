#pragma once

#include "Material.h"

class Dielectric : public Material
{
public:
	Dielectric(float refInd);
	~Dielectric();

	virtual bool scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const override;

protected:
	bool refract(const Vector3& v, const Vector3& n, float niOverNt, Vector3& refracted)const;
	float schlick(float cosine) const;

private:
	float refractiveIndex;
};