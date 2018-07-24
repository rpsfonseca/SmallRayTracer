#include "Camera.h"

#include "maths\Math.h"

Camera::Camera()
{
    bottomLeft = Vector3(-2.0, -1.0, -1.0);
	horizontal = Vector3(4.0, 0.0, 0.0);
	vertical = Vector3(0.0, 2.0, 0.0);
	origin = Vector3(0.0, 0.0, 0.0);
}

Camera::Camera(const Vector3& pos, const Vector3& lookAt, const Vector3& up, float fov, float aspectRatio)
	: origin(pos)
{
	Vector3 u, v, w;
	float theta = fov * (maths::PI) / 180;
	float h = tan(theta / 2); // Half height is the ratio to the distance of the z plane where the rays are headed
	float halfWidth = aspectRatio * h;

	w = normalize(origin - lookAt);
	u = normalize(cross(up, w));
	v = cross(w, u);
	bottomLeft = origin - halfWidth * u - h * v - w;
	horizontal = 2 * halfWidth * u;
	vertical = 2 * h * v;
}

Camera::~Camera()
{
}

Ray Camera::getRay(float u, float v)
{
    return Ray(origin, (bottomLeft + u * horizontal + v * vertical - origin));
}