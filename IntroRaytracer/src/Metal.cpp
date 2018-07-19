#include "Metal.h"

Metal::Metal(const Vector3& a)
    : albedo(a)
{
}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const
{
    Vector3 reflected = reflect(normalize(inRay.direction), hitInfo.normal);
    scatteredRay = Ray(hitInfo.hitPoint, reflected);
    attenuation = albedo;
    return (dot(scatteredRay.direction, hitInfo.normal) > 0);
}