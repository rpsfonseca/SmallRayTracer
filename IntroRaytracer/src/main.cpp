#include <iostream>
#include <fstream>
#include <random>

#include "ray.h"
#include "geometry/Sphere.h"
#include "scene.h"
#include "Camera.h"
#include "Material.h"
#include "Lambert.h"
#include "Metal.h"
#include "maths/Math.h"

#define MAX_FLOAT 1.0e07f

Scene world = Scene();

Vector3 getColor(const Ray& r, int depth)
{
	Hit hitInfo;
	if(world.trace(r, 0.001, MAX_FLOAT, hitInfo))
	{
		Ray scatteredRay;
		Vector3 attenuation;
		if(depth < 50 && hitInfo.material->scatter(r, hitInfo, attenuation, scatteredRay))
		{
			return attenuation * getColor(scatteredRay, depth + 1);
		}
		else
		{
			return Vector3(0, 0, 0);
		}
		/*Vector3 target = hitInfo.hitPoint + hitInfo.normal + randomInUnitSphere();
		return 0.5 * getColor(Ray(hitInfo.hitPoint, target - hitInfo.hitPoint));*/
	}
	else
	{
		Vector3 unitDir = normalize(r.direction);
		double t = 0.5 * (unitDir.y + 1.0);
		return (1.0 - t) * Vector3(1.0,1.0,1.0) + t * Vector3(0.5, 0.7, 1.0);
	}
}

int main()
{
	int nx = 600;
	int ny = 300;
	int numOfSamples = 100;

	Camera camera = Camera();

	std::ofstream outputFile("../resources/testImg.ppm");

	Object* objectList[4];
	objectList[0] = new Sphere(Vector3(0, 0, -1), 0.5f, new Lambert(Vector3(0.8, 0.3, 0.3)));
	objectList[1] = new Sphere(Vector3(0, -100.5, -1), 100, new Lambert(Vector3(0.8, 0.8, 0.0)));
	objectList[2] = new Sphere(Vector3(1, 0, -1), 0.5f, new Metal(Vector3(0.8, 0.6, 0.2)));
	objectList[3] = new Sphere(Vector3(-1, 0, -1), 0.5f, new Metal(Vector3(0.8, 0.8, 0.8)));

	for (int i = 0; i < 4; i++)
	{
		world.addObject(objectList[i]);
	}

	outputFile << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			Vector3 color = Vector3(0.0f, 0.0f, 0.0f);
			for(int s = 0; s < numOfSamples; s++)
			{
				float u = float(i + maths::generateRand01()) / float(nx);
				float v = float(j + maths::generateRand01()) / float(ny);
				Ray r = camera.getRay(u, v);
				color += getColor(r, 0);
			}
			color /= float(numOfSamples);
			color = Vector3(sqrt(color.x), sqrt(color.y), sqrt(color.z));
			int ir = int(255.99 * color.x);
			int ig = int(255.99 * color.y);
			int ib = int(255.99 * color.z);
			outputFile << ir << " " << ig << " " << ib << "\n";
		}
	}
	outputFile.close();

	for (int i = 0; i < 4; i++)
	{
		delete objectList[i];
	}
	return 0;
}