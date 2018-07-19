#pragma once

#include "geometry/Object.h"

#include <vector>

class Scene
{
public:
    std::vector<Object*> objects;
public:
    Scene(/* args */);
    ~Scene();

    void addObject(Object* object);
    bool trace(const Ray& r, float tMin, float tMax, Hit& hitInfo);
};

