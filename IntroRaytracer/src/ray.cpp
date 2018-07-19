#include "ray.h"

Ray::Ray()
{
}

Ray::Ray(const Vector3& o, const Vector3& d)
    : origin(o), direction(d)
{
}

Vector3 Ray::pointAt(float t) const
{
    return origin + t * direction;
}