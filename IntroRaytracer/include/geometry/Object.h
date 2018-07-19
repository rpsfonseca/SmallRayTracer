#pragma once
#include "../ray.h"
#include "../Hit.h"
#include "../Material.h"

class Object
{
private:
    
public:
    Object();
    ~Object();

    virtual bool intersect(const Ray& ray, float tMin, float tMax, Hit& hitInfo) = 0;
};