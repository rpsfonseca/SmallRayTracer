#pragma once

#include <random>

#include "vec3.h"

namespace maths
{
	const double PI = 3.14;

	inline double generateRand01()
	{
		return ((double)rand() / (RAND_MAX));
	}

	inline Vector3 randomInUnitSphere()
	{
		Vector3 randomPoint;

		while (!(randomPoint.sqLength() >= 1.0))
		{
			randomPoint = 2.0 * Vector3(generateRand01(), generateRand01(), generateRand01()) - Vector3(1, 1, 1);
		}

		return randomPoint;
	}
}