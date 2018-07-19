#pragma once

#include "maths/vec3.h"

class Ray
{
public:
    Vector3 origin;
    Vector3 direction;
    
public:
    Ray();
    Ray(const Vector3& o, const Vector3& d);

    Vector3 pointAt(float t) const;
};