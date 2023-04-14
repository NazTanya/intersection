#include"Vector3D.h"

#include "DefaultPlane.h"
#include "IntersectionType.h"

#include<iostream>
#include <limits>


class Segment3D
{
	Vector3D _start;
	Vector3D _end;
public:
	Segment3D(Vector3D start, Vector3D end) {
		_start = start;
		_end = end;
	}
	void Set(Vector3D start, Vector3D end) {
		_start = start;
		_end = end;
	}
	IntersectionType Intersection(const Segment3D& segment, Vector3D& result, double eps = 1e-8) {
		if (!this->IsInOnePlane(segment))
		{
			result = Vector3D(std::numeric_limits<double>::max());
			return IntersectionType::NoIntersection;
		}
		else {
			double numerator_t = CalculateNumerator_t(*this, segment, DefaultPlane::XY);
			double numerator_u = CalculateNumerator_u(*this, segment, DefaultPlane::XY);
			double denominator = CalculateDenominator(*this, segment, DefaultPlane::XY);
			if (std::abs(denominator) < eps) {
				numerator_t = CalculateNumerator_t(*this, segment, DefaultPlane::XZ);
				numerator_u = CalculateNumerator_u(*this, segment, DefaultPlane::XZ);
				denominator = CalculateDenominator(*this, segment, DefaultPlane::XZ);
				if (std::abs(denominator) < eps) {

					if ((_start - _end).DotProduct(segment._start - _end) < 0
						|| (segment._start - segment._end).DotProduct(_start - segment._end) < 0)
					{
						result =  Vector3D(std::numeric_limits<double>::max());
						return IntersectionType::OnOneLineNoIntersection;
					}
					else
					{
						result = _end;
						return IntersectionType::OnOneLineIntersection;
					}
				}
				else {
					double ratio_t = numerator_t / denominator;
					double ratio_u = numerator_u / denominator;
					if (ratio_t <= 1 && ratio_t >= eps && ratio_u <= 1 && ratio_u >= eps) {
						result =  Vector3D(_start.X + ratio_t * (_end.X - _start.X),
							_start.Y + ratio_t * (_end.Y - _start.Y),
							_start.Z + ratio_t * (_end.Z - _start.Z));
						return IntersectionType::HasIntersection;
					}
					else
					{
						result = Vector3D(std::numeric_limits<double>::max());
						return IntersectionType::NoIntersection;
					}
				}
			}
		}
	}
	void PrintSegment() {
		std::cout << "Отрезок: (" << _start.X << ", " << _start.Y << ", " << _start.Z << ")  (" << _end.X << ", " << _end.Y << ", " << _end.Z << ")" << std::endl;
	}
private:
	bool IsInOnePlane (const Segment3D& segment) {
		Vector3D a(_start - _end);
		Vector3D b(_start - segment._start);
		Vector3D c(_start - segment._end);

		if ((a.X * b.Y * c.Z) + (c.X * a.Y * b.Z) + (b.X * c.Y * a.Z) - 
			(c.X * b.Y * a.Z) - (b.X * a.Y * c.Z) - (a.X * c.Y * b.Z) == 0)
			return true;
		else
			return false;
	}

	double CalculateNumerator_t(const Segment3D& a, const Segment3D& b, DefaultPlane defaultPlane) {
		switch (defaultPlane)
		{
		case XY:
			return (a._start.X - b._start.X) * (b._start.Y - b._end.Y) - 
				(a._start.Y - b._start.Y) * (b._start.X - b._end.X);
		case XZ:
			return (a._start.X - b._start.X) * (b._start.Z - b._end.Z) -
				(a._start.Z - b._start.Z) * (b._start.X - b._end.X);
		}
	}

	double CalculateDenominator(const Segment3D& a, const Segment3D& b, DefaultPlane defaultPlane) {
		switch (defaultPlane)
		{
		case XY:
			return (a._start.X - a._end.X) * (b._start.Y - b._end.Y) - 
				(a._start.Y - a._end.Y) * (b._start.X - b._end.X);
		case XZ:
			return (a._start.X - a._end.X) * (b._start.Z - b._end.Z) -
				(a._start.Z - a._end.Z) * (b._start.X - b._end.X);
		}
	}

	double CalculateNumerator_u(const Segment3D& a, const Segment3D& b, DefaultPlane defaultPlane) {
		switch (defaultPlane)
		{
		case XY:
			return (a._start.X - b._start.X) * (a._start.Y - a._end.Y) -
				(a._start.Y - b._start.Y) * (a._start.X - a._end.X);
		case XZ:
			return (a._start.X - b._start.X) * (a._start.Z - a._end.Z) -
				(a._start.Z - b._start.Z) * (a._start.X - a._end.X);
		}
	}

};