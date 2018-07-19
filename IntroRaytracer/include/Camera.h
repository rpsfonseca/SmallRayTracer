#pragma once

#include "maths/vec3.h"
#include "ray.h"

class Camera
{
private:
    Vector3 bottomLeft;
    Vector3 origin;
    Vector3 horizontal;
    Vector3 vertical;

public:
    Camera();
    ~Camera();

    Ray getRay(float u, float v);
};

