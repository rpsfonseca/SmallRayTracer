#include "Metal.h"
#include "maths\Math.h"

Metal::Metal(const Vector3& a, float f)
    : albedo(a)
{
	if (f < 1)
	{
		fuzziness = f;
	}
	else
	{
		fuzziness = 1;
	}
}

Metal::~Metal() {}

bool Metal::scatter(const Ray& inRay, const Hit& hitInfo, Vector3& attenuation, Ray& scatteredRay) const
{
    Vector3 reflected = reflect(normalize(inRay.direction), hitInfo.normal);
    scatteredRay = Ray(hitInfo.hitPoint, reflected + (fuzziness * maths::randomInUnitSphere()));
    attenuation = albedo;
    return (dot(scatteredRay.direction, hitInfo.normal) > 0);
}