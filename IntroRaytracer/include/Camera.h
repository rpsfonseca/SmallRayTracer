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
	Vector3 u, v, w;
	float lensRadius;

public:
    Camera();
	Camera(const Vector3& pos, const Vector3& lookAt, const Vector3& up, float fov, float aspectRatio, float aperture, float focusDistance);
    ~Camera();

    Ray getRay(float s, float t);
};

