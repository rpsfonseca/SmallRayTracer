#pragma once

#include <math.h>

struct Vector3
{
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {};
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};

	float sqLength() const { return x*x + y*y + z*z; }
	float length() const { return sqrtf(x*x + y*y + z*z); }
	void normalize() { float k = 1.0f / length(); x *= k; y *= k; z *= k; }

	Vector3 operator-() const { return Vector3(-x,-y,-z); }
	Vector3& operator+=(const Vector3& v) { x += v.x; y += v.y; z += v.z; return *this; }
	Vector3& operator-=(const Vector3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
	Vector3& operator*=(const Vector3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
	Vector3& operator*=(const float t) { x *= t; y *= t; z *= t; return *this; }
	Vector3& operator/=(const float t) { x /= t; y /= t; z /= t; return *this; }

};

inline Vector3 operator+(const Vector3& a, const Vector3& b) { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline Vector3 operator-(const Vector3& a, const Vector3& b) { return Vector3(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vector3 operator*(const Vector3& a, const Vector3& b) { return Vector3(a.x * b.x, a.y * b.y, a.z * b.z); }
inline Vector3 operator*(const Vector3& b, float a) { return Vector3(a*b.x,a*b.y,a*b.z); }
inline Vector3 operator*(float a, const Vector3& b) { return Vector3(a*b.x,a*b.y,a*b.z); }

inline Vector3 normalize(const Vector3& v) { float k = 1.0f / v.length(); return Vector3(v.x * k, v.y * k, v.z * k); }
inline float dot(const Vector3& v1, const Vector3& v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;  }
inline Vector3 reflect(const Vector3& v, const Vector3& n) { return v - 2*dot(v,n)*n; }