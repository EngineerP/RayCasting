#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
	const Ray& ray, const double min_t, double& t, Eigen::Vector3d& n) const
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:
	if (ray.direction.dot(this->normal) == 0) return false;
	double tTemp = (((this->point) - ray.origin).dot(this->normal)) / (ray.direction.dot(this->normal));
	if (tTemp < min_t) return false;

	t = tTemp;
	n = this->normal;
	return true;
	////////////////////////////////////////////////////////////////////////////
}
