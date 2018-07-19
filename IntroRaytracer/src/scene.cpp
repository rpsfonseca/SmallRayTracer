#include "scene.h"

Scene::Scene()
{
    objects = std::vector<Object*>();
}

Scene::~Scene()
{
    for (std::vector<Object*>::iterator it = objects.begin() ; it != objects.end(); ++it)
   {
     delete (*it);
   } 
   objects.clear();
}

void Scene::addObject(Object* object)
{
    objects.push_back(object);
}

bool Scene::trace(const Ray& r, float tMin, float tMax, Hit& hitInfo)
{
    Hit localHit;
    bool didHit = false;
    double closest = tMax;

    for(Object* object : objects)
    {
        if(object->intersect(r, tMin, closest, localHit))
        {
            didHit = true;
            closest = localHit.t;
            hitInfo = localHit;
        }
    }
    return didHit;
}