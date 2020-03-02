#include "first_hit.h"

bool first_hit(
	const Ray& ray,
	const double min_t,
	const std::vector< std::shared_ptr<Object> >& objects,
	int& hit_id,
	double& t,
	Eigen::Vector3d& n)
{
	////////////////////////////////////////////////////////////////////////////
	// Replace with your code here:
	bool hitObject = false;
	int hitIDTemp;
	double tMinTemp = std::numeric_limits<double>::max();
	Eigen::Vector3d nMinTemp;

	for (int i = 0; i < objects.size(); i++) {
		double tTemp = std::numeric_limits<double>::max();
		Eigen::Vector3d nTemp;
		if (objects[i]->intersect(ray, min_t, tTemp, nTemp) && tTemp < tMinTemp) {
			tMinTemp = tTemp;
			nMinTemp = nTemp;
			hitIDTemp = i;
			hitObject = true;
		}
	}

	if (hitObject) {
		t = tMinTemp;
		n = nMinTemp;
		hit_id = hitIDTemp;
		return true;
	}

	return false;
	////////////////////////////////////////////////////////////////////////////
}