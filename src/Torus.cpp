#include <vector>
#include <math.h>

#include "Torus.h"

constexpr double pi = 3.14;

template<typename T>
Point<T>::Point(const T x, const T y, const T z) : x(x), y(y), z(z) {}

template<typename T>
T Point<T>::getX() {
	return x;
}

template<typename T>
T Point<T>::getY() {
	return y;
}

template<typename T>
T Point<T>::getZ() {
	return z;
}

template<typename T>
Figure<T>::Figure() {};

template<typename T>
std::vector<Point<T>> Figure<T>::getPoints() {
	return points;
}

Torus::Torus(const int R1, const int R2, const int density) : R1(R1), R2(R2) {
	points.reserve(density * density);
	double angleGain = 2 * pi / density;
	for (double u = 0; u < 2 * pi; u += angleGain) {
		for (double v = 0; v < 2 * pi; v += angleGain) {
			points.push_back(Point<double>(getX(u, v), getY(u, v), getZ(v)));

		}
	}
}

double Torus::getX(const double& u, const double& v) {
	return (R1 + R2 * cos(v)) * cos(u);
}

double Torus::getY(const double& u, const double& v) {
	return (R1 + R2 * cos(v)) * sin(u);
}

double Torus::getZ(const double& v) {
	return R2 * sin(v);
}
