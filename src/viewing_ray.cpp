#include "viewing_ray.h"

void viewing_ray(
	const Camera& camera,
	const int i,
	const int j,
	const int width,
	const int height,
	Ray& ray)
{
	////////////////////////////////////////////////////////////////////////////
	// Add your code here

	double l = camera.width * -0.5;
	double r = camera.width * 0.5;
	double b = camera.height * -0.5;
	double t = camera.height * 0.5;

	//As Formula 4.1 from the textbook
	double u = l + ((r - l) * (j + 0.5)) / width;
	double v = b + ((t - b) * ((height - 1 - i) + 0.5)) / height;

	ray.origin = camera.e;
	ray.direction = ((-camera.d) * camera.w) + (u * camera.u) + (v * camera.v);
	////////////////////////////////////////////////////////////////////////////
}
