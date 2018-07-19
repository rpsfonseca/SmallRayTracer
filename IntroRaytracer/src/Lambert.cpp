#include "Lambert.h"
#include "maths/Math.h"

Lambert::Lambert(const Vector3& a)
    : albedo(a)
{
}

Lambert::~Lambert()
{
}

bool Lambert::scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const
{
    Vector3 target = hitInfo.hitPoint + hitInfo.normal + maths::randomInUnitSphere();
    scatteredRay = Ray(hitInfo.hitPoint, target - hitInfo.normal);
    attenuation = albedo;
    return true;
}