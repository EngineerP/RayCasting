#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
	const Ray& ray, const double min_t, double& t, Eigen::Vector3d& n) const
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:
	double determinant;
	Eigen::Vector3d d = ray.direction;
	Eigen::Vector3d e = ray.origin;
	Eigen::Vector3d c = this->center;
	determinant = pow(d.dot(e - c), 2) - ((d.dot(d)) * ((e - c).dot(e - c) - pow(this->radius, 2)));
	if (determinant == 0) {
		t = (-d.dot(e - c)) / (d.dot(d));
		n = 2.0 * (e + t * d - c);
		return true;
	}
	else if (determinant > 0) {
		double tPlus = ((-d).dot(e - c) + sqrt(determinant)) / (d.dot(d));
		double tMinus = ((-d).dot(e - c) - sqrt(determinant)) / (d.dot(d));
		if (tMinus >= min_t && tMinus < tPlus) t = tMinus;
		else if (tPlus >= min_t) t = tPlus;
		else return false;
		n = 2.0 * (e + t * d - c);
		return true;
	}
	return false;
	////////////////////////////////////////////////////////////////////////////
}
