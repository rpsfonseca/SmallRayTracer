#pragma once

#include "maths/vec3.h"
//#include "Material.h"

class Material;

struct Hit
{
    float t;
    Vector3 hitPoint;
    Vector3 normal;
    Material* material;
};
