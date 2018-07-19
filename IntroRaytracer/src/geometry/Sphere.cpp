#include "geometry/Sphere.h"

#include <math.h>

Sphere::Sphere()
{
}

Sphere::Sphere(Vector3 c, float r)
    : center(c), radius(r), invRadius(1.0f/r)
{
}

Sphere::Sphere(Vector3 c, float r, Material* mat)
	: Sphere(c,r)
{
	material = mat;
}

Sphere::~Sphere()
{
}

bool Sphere::intersect(const Ray& ray, float tMin, float tMax, Hit& hitInfo)
{
    Vector3 oc = ray.origin - center;
    float a = dot(ray.direction, ray.direction);
    float b = dot(ray.direction, oc);
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;

    if (discriminant > 0)
    {
        float discrSqrt = sqrt(discriminant);
        float temp = (-b - discrSqrt) / a;
        if (temp < tMax && temp > tMin)
        {
            hitInfo.t = temp;
            hitInfo.hitPoint = ray.pointAt(temp);
            hitInfo.normal = (hitInfo.hitPoint - center) * invRadius;
			hitInfo.material = material;
            return true;
        }

        temp = (-b + discrSqrt) / a;
        if (temp < tMax && temp > tMin)
        {
            hitInfo.t = temp;
            hitInfo.hitPoint = ray.pointAt(temp);
            hitInfo.normal = (hitInfo.hitPoint - center) * invRadius;
			hitInfo.material = material;
            return true;
        }
    }
    return false;
}