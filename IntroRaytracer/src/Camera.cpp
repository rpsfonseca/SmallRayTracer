#include "Camera.h"

#include "maths\Math.h"

Camera::Camera()
{
    bottomLeft = Vector3(-2.0, -1.0, -1.0);
	horizontal = Vector3(4.0, 0.0, 0.0);
	vertical = Vector3(0.0, 2.0, 0.0);
	origin = Vector3(0.0, 0.0, 0.0);
}

Camera::Camera(const Vector3& pos, const Vector3& lookAt, const Vector3& up, float fov, float aspectRatio, float aperture, float focusDistance)
	: origin(pos)
{
	float theta = fov * (maths::PI) / 180;
	float h = tan(theta / 2); // Half height is the ratio to the distance of the z plane where the rays are headed
	float halfWidth = aspectRatio * h;

	w = normalize(pos - lookAt);
	u = normalize(cross(up, w));
	v = cross(w, u);
	bottomLeft = origin - halfWidth * focusDistance * u - h * focusDistance * v - focusDistance*w;
	horizontal = 2 * halfWidth * focusDistance * u;
	vertical = 2 * h  * focusDistance * v;
	lensRadius = aperture / 2;
}

Camera::~Camera()
{
}

Ray Camera::getRay(float s, float t)
{
	Vector3 randomPoint = lensRadius * maths::randomInUnitDisk();
	Vector3 offset = u * randomPoint.x + v * randomPoint.y;
    return Ray(origin + offset, normalize(bottomLeft + s * horizontal + t * vertical - origin - offset));
}