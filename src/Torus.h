#pragma once
#include <vector>
#include <iostream>

template<typename T>
class Point {
public:
	Point(const T x, const T y, const T z);
	T getX();
	T getY();
	T getZ();
	friend std::ostream& operator<<(std::ostream& stream, const Point& point) {
		stream << "(" << point.x << ", " << point.y << ", " << point.z << ")";
		return stream;
	}
private:
	T x, y, z;
};

template<typename T>
class Figure {
public:
	Figure();
	std::vector<Point<T>> getPoints();
	friend std::ostream& operator<<(std::ostream& stream, const Figure& fig) {
		stream << "[";
		for (const auto& point : fig.points) {
			stream << point << " ";
		}
		stream << "]";
		return stream;
	}
	
protected:
	std::vector<Point<T>> points;
};

class Torus : public Figure<double> {
public:
	Torus(const int R1, const int R2, const int numberOfPoints);
	double getX(const double& u, const double& v);
	double getY(const double& u, const double& v);
	double getZ(const double& v);
private:
	const int R1; // Radius of torus hole
	const int R2; // Radius of torus body
};
