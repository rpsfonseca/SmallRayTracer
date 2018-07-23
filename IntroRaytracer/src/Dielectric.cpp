#include "Dielectric.h"

#include "maths\Math.h"

Dielectric::Dielectric(float refInd)
	: refractiveIndex(refInd)
{
}

Dielectric::~Dielectric()
{
}

bool Dielectric::scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const
{
	Vector3 refracted;
	Vector3 outNormal;
	Vector3 reflected = reflect(inRay.direction, hitInfo.normal);
	float niOverNt;
	float reflectProb;
	float cosine;

	attenuation = Vector3(1.0, 1.0, 1.0);

	if (dot(inRay.direction, hitInfo.normal) > 0)
	{
		outNormal = -hitInfo.normal;
		niOverNt = refractiveIndex;
		cosine = refractiveIndex * dot(inRay.direction, hitInfo.normal) / inRay.direction.length();
	}
	else
	{
		outNormal = hitInfo.normal;
		niOverNt = 1.0 / refractiveIndex;
		cosine = -dot(inRay.direction, hitInfo.normal) / inRay.direction.length();
	}

	if (refract(inRay.direction, outNormal, niOverNt, refracted))
	{
		reflectProb = schlick(cosine);
	}
	else
	{
		reflectProb = 1.0;
	}

	if (maths::generateRand01() < reflectProb)
	{
		scatteredRay = Ray(hitInfo.hitPoint, reflected);
	}
	else
	{
		scatteredRay = Ray(hitInfo.hitPoint, refracted);
	}

	return true;
}

bool Dielectric::refract(const Vector3& v, const Vector3& n, float niOverNt, Vector3& refracted) const
{
	Vector3 uv = normalize(v);
	float dt = dot(uv, n);
	float discriminant = 1.0 - niOverNt * niOverNt*(1 - dt * dt);
	if (discriminant > 0)
	{
		refracted = niOverNt * (uv - n * dt) - n * sqrt(discriminant);
		return true;
	}
	else
	{
		return false;
	}
}

float Dielectric::schlick(float cosine) const
{
	float r0 = (1 - refractiveIndex) / (1 + refractiveIndex);
	r0 *= r0;
	return r0 + (1 - r0) * pow((1 - cosine), 5);
}