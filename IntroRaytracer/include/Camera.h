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
	Camera(const Vector3& pos, const Vector3& lookAt, const Vector3& up, float fov, float aspectRatio);
    ~Camera();

    Ray getRay(float u, float v);
};

