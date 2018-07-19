#pragma once
#include "Object.h"

class Sphere : public Object
{
private:
    Vector3 center;
    float radius;
    float invRadius;
	Material* material;
    
public:
    Sphere();
    Sphere(Vector3 c, float r);
	Sphere(Vector3 c, float r, Material* mat);
    ~Sphere();

    virtual bool intersect(const Ray& ray, float tMin, float tMax, Hit& hitInfo) override;
};

