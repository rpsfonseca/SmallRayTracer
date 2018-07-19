#include "Camera.h"

Camera::Camera()
{
    bottomLeft = Vector3(-2.0, -1.0, -1.0);
	horizontal = Vector3(4.0, 0.0, 0.0);
	vertical = Vector3(0.0, 2.0, 0.0);
	origin = Vector3(0.0, 0.0, 0.0);
}

Camera::~Camera()
{
}

Ray Camera::getRay(float u, float v)
{
    return Ray(origin, (bottomLeft + u * horizontal + v * vertical - origin));
}